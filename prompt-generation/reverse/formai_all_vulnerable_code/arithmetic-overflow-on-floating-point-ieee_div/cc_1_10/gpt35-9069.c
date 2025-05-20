//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <sys/time.h>
#include <curl/curl.h>

#define SPEED_TEST_SERVER "http://speedtest.website.com"
#define DOWNLOAD_FILE_PATH "/tmp/speedtest-download"
#define UPLOAD_FILE_PATH "/tmp/speedtest-upload"
#define DOWNLOAD_FILE_SIZE (10 * 1024 * 1024)   /* 10 MB */
#define UPLOAD_FILE_SIZE (5 * 1024 * 1024)  /* 5 MB */

struct MemoryStruct {
  char *memory;
  size_t size;
};

/* callback function for CURLOPT_WRITEFUNCTION */
static size_t write_callback(void *ptr, size_t size, size_t nmemb, void *data)
{
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *) data;
  mem->memory = realloc(mem->memory, mem->size + realsize + 1);
  if(mem->memory == NULL) {
    fprintf(stderr, "realloc() failed\n");
    return 0;
  }
  memcpy(&(mem->memory[mem->size]), ptr, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = '\0';
  return realsize;
}

/* perform download test */
double perform_download_test(CURL *curl)
{
  double speed = 0.0;
  CURLcode res;
  struct MemoryStruct chunk;
  chunk.memory = malloc(1);
  chunk.size = 0;
  FILE *fp = fopen(DOWNLOAD_FILE_PATH, "wb");
  if(fp == NULL) {
    fprintf(stderr, "Unable to create file: %s\n", DOWNLOAD_FILE_PATH);
    return -1.0;
  }
  curl_easy_setopt(curl, CURLOPT_URL, SPEED_TEST_SERVER "/download");
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
  struct timeval start, end;
  gettimeofday(&start, NULL);
  res = curl_easy_perform(curl);
  if(res != CURLE_OK) {
    fprintf(stderr, "Download test failed: %s\n", curl_easy_strerror(res));
    return -1.0;
  }
  fwrite(chunk.memory, 1, chunk.size, fp);
  fclose(fp);
  gettimeofday(&end, NULL);
  double total_time = (end.tv_sec - start.tv_sec) + 
                      (double) (end.tv_usec - start.tv_usec) / 1000000.0;
  speed = (double) ((DOWNLOAD_FILE_SIZE * 8) / (1024 * 1024)) / total_time;
  printf("Download speed: %0.2f Mbps\n", speed);
  free(chunk.memory);
  return speed;
}

/* perform upload test */
double perform_upload_test(CURL *curl)
{
  double speed = 0.0;
  CURLcode res;
  struct MemoryStruct chunk;
  chunk.memory = malloc(1);
  chunk.size = 0;
  char *data = (char *) malloc(UPLOAD_FILE_SIZE);
  memset(data, 'A', UPLOAD_FILE_SIZE);
  FILE *fp = fopen(UPLOAD_FILE_PATH, "wb");
  if(fp == NULL) {
    fprintf(stderr, "Unable to create file: %s\n", UPLOAD_FILE_PATH);
    return -1.0;
  }
  fwrite(data, 1, UPLOAD_FILE_SIZE, fp);
  fclose(fp);
  free(data);

  struct curl_httppost *form;
  struct curl_httppost *last;
  form = NULL;
  last = NULL;
  curl_formadd(&form, &last, CURLFORM_COPYNAME, "upload", 
               CURLFORM_FILE, UPLOAD_FILE_PATH, CURLFORM_END);
  curl_easy_setopt(curl, CURLOPT_URL, SPEED_TEST_SERVER "/upload");
  curl_easy_setopt(curl, CURLOPT_HTTPPOST, form);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
  struct timeval start, end;
  gettimeofday(&start, NULL);
  res = curl_easy_perform(curl);
  if(res != CURLE_OK) {
    fprintf(stderr, "Upload test failed: %s\n", curl_easy_strerror(res));
    return -1.0;
  }
  curl_formfree(form);
  gettimeofday(&end, NULL);
  double total_time = (end.tv_sec - start.tv_sec) + 
                      (double) (end.tv_usec - start.tv_usec) / 1000000.0;
  speed = (double) ((UPLOAD_FILE_SIZE * 8) / (1024 * 1024)) / total_time;
  printf("Upload speed: %0.2f Mbps\n", speed);
  free(chunk.memory);
  return speed;
}

int main()
{
  CURL *curl = curl_easy_init();
  if(curl == NULL) {
    fprintf(stderr, "Unable to initialize curl\n");
    return 1;
  }
  double download_speed = perform_download_test(curl);
  double upload_speed = perform_upload_test(curl);
  printf("Overall speed: %0.2f Mbps\n", (download_speed + upload_speed) / 2.0);
  curl_easy_cleanup(curl);
  return 0; 
}