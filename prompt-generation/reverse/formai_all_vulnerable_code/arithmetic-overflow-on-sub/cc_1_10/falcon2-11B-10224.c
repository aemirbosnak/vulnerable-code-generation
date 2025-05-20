//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

double get_time() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec / 1000000.0;
}

int main(int argc, char *argv[]) {
  double start_time = get_time();

  char download_cmd[256];
  char upload_cmd[256];

  printf("Please wait...\n");

  snprintf(download_cmd, sizeof(download_cmd), "curl -s -o /dev/null -w \"%{time_total}\" %s", argv[1]);
  snprintf(upload_cmd, sizeof(upload_cmd), "wget -O /dev/null --spider %s", argv[2]);

  int download_start_time = get_time();
  int download_end_time = get_time();

  int upload_start_time = get_time();
  int upload_end_time = get_time();

  // Download test
  int status = system(download_cmd);
  if (status == 0) {
    download_end_time = get_time();
    double download_time = download_end_time - download_start_time;
    double download_speed = 8 * 1000 * 1000 / download_time;
    printf("Download Speed: %.2f Mbps\n", download_speed);
  }

  // Upload test
  status = system(upload_cmd);
  if (status == 0) {
    upload_end_time = get_time();
    double upload_time = upload_end_time - upload_start_time;
    double upload_speed = 8 * 1000 * 1000 / upload_time;
    printf("Upload Speed: %.2f Mbps\n", upload_speed);
  }

  double total_time = get_time() - start_time;
  printf("Total Time: %.2f seconds\n", total_time);

  return 0;
}