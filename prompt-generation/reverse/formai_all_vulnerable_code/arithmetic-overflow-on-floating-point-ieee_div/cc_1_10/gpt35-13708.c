//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 10000000 // 10MB

double calculateDownloadSpeed() {
  int i;
  time_t start, end;

  // Get current time at start
  start = time(NULL);

  // Open a URL and perform download
  system("curl -o /dev/null https://speedtest.pixelwolf.ca/10MB.zip");

  // Get current time at end
  end = time(NULL);

  // Calculate time elapsed in seconds
  double elapsedTime = difftime(end, start);

  // Calculate download speed in Megabits per second (Mbps)
  double downloadSpeed = (SIZE / elapsedTime) / 125000;

  return downloadSpeed;
}

double calculateUploadSpeed() {
  int i;
  time_t start, end;

  // Create temp file of 10MB
  FILE *fp;
  fp = fopen("tmp", "w");
  for (i = 0; i < SIZE; i++) {
    fprintf(fp, "%c", 'A'+i%26);
  }
  fclose(fp);

  // Get current time at start
  start = time(NULL);

  // Upload file to server
  system("curl -H 'Max-Upload-Rate: 100000' -T tmp ftp://speedtest.pixelwolf.ca/");

  // Get current time at end
  end = time(NULL);

  // Delete temp file
  system("rm tmp");

  // Calculate time elapsed in seconds
  double elapsedTime = difftime(end, start);

  // Calculate upload speed in Megabits per second (Mbps)
  double uploadSpeed = (SIZE / elapsedTime) / 125000;

  return uploadSpeed;
}

int main() {
  double downloadSpeed, uploadSpeed;

  // Calculate and print download speed
  downloadSpeed = calculateDownloadSpeed();
  printf("Download speed: %.2f Mbps\n", downloadSpeed);

  // Wait for 30 seconds before calculating upload speed
  printf("Calculating upload speed in 30 seconds...\n");
  sleep(30);

  // Calculate and print upload speed
  uploadSpeed = calculateUploadSpeed();
  printf("Upload speed: %.2f Mbps\n", uploadSpeed);

  return 0;
}