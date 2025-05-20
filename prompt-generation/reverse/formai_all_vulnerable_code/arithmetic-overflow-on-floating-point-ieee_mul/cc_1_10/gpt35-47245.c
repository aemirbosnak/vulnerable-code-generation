//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
  // Variables to hold information about internet speed
  float download_speed, upload_speed;
  int download_time, upload_time;

  // Prompt user for their download speed
  printf("Please enter your internet download speed in Mbps: ");
  scanf("%f", &download_speed);

  // Prompt user for their upload speed
  printf("Please enter your internet upload speed in Mbps: ");
  scanf("%f", &upload_speed);

  // Calculate estimated download time for a 1GB file in seconds
  download_time = (int) ((1 * 1024 * 1024 * 8) / (download_speed * 1000000));
  printf("Estimated download time for a 1GB file: %d seconds\n", download_time);

  // Calculate estimated upload time for a 1GB file in seconds
  upload_time = (int) ((1 * 1024 * 1024 * 8) / (upload_speed * 1000000));
  printf("Estimated upload time for a 1GB file: %d seconds\n", upload_time);

  // Speed test server URL to get download speed
  char *download_server = "https://test-dec16d6c.s3.amazonaws.com/1GBtestfile.bin";
  // Speed test server URL to get upload speed
  char *upload_server = "https://speedtest.tele2.net/upload.php";
  // Temporary filename to hold the downloaded file
  char *temp_filename = "/tmp/download_speed_test.tmp";
  // Size of the downloaded file in bytes
  int download_file_size;

  // Command to download the file from the speed test server for measuring download speed
  char download_command[1024];
  sprintf(download_command, "curl --output %s %s", temp_filename, download_server);

  // Command to upload a 1MB file to the speed test server for measuring upload speed
  char upload_command[1024];
  sprintf(upload_command, "curl -F 'file=@/dev/urandom' %s", upload_server);

  // Measure download speed
  printf("Measuring download speed...\n");
  system(download_command);
  FILE *download_file = fopen(temp_filename, "r");
  if (download_file != NULL) {
    fseek(download_file, 0, SEEK_END);
    download_file_size = ftell(download_file) * 8;
    fclose(download_file);
    float download_speed_measured = (download_file_size / download_time) / 1000000.0;
    printf("Your measured download speed: %.2f Mbps\n", download_speed_measured);
    int status = remove(temp_filename); // Delete temp file
  } else {
    printf("Download test failed. Please check your internet connection\n");
  }

  // Measure upload speed
  printf("Measuring upload speed...\n");
  FILE *upload_file = fopen("/dev/urandom", "r");
  if (upload_file != NULL) {
    int upload_file_bytes_read = 0;
    time_t start_time = time(NULL);
    int upload_time_elapsed = 0;
    while (upload_time_elapsed < upload_time) { // Send 1MB chunks until upload time is reached
      char chunk[1024 * 1024];
      for (int i = 0; i < 1024 * 1024; i++) {
        chunk[i] = fgetc(upload_file);
        upload_file_bytes_read++;
      }
      FILE *upload_pipe = popen(upload_command, "r");
      if (upload_pipe == NULL) {
        printf("Upload test failed. Please check your internet connection\n");
        fclose(upload_file);
        exit(0);
      } else {
        pclose(upload_pipe);
      }
      upload_time_elapsed = time(NULL) - start_time;
    }
    fclose(upload_file);
    float upload_speed_measured = (upload_file_bytes_read / upload_time) / 1000000.0;
    printf("Your measured upload speed: %.2f Mbps\n", upload_speed_measured);
  } else {
    printf("Upload test failed. Please check your internet connection\n");
  }

  return 0;
}