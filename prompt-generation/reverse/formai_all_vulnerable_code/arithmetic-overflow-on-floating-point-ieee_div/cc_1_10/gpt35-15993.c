//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Declare variables
  int download_speed, upload_speed, latency;
  double download_time, upload_time;

  // Get user input
  printf("Enter your internet download speed in Mbps: ");
  scanf("%d", &download_speed);
  printf("Enter your internet upload speed in Mbps: ");
  scanf("%d", &upload_speed);
  printf("Enter your internet latency in milliseconds: ");
  scanf("%d", &latency);

  // Calculate download time
  download_time = 1000000.0 * 8.0 / (download_speed * 1000000.0);
  printf("Your download time for 1 GB file is: %f hours\n", download_time);

  // Calculate upload time
  upload_time = 1000000.0 * 8.0 / (upload_speed * 1000000.0);
  printf("Your upload time for 1 GB file is: %f hours\n", upload_time);

  // Calculate latency in seconds
  double latency_sec = (double) latency / 1000.0;
  printf("Your latency is: %f seconds\n", latency_sec);

  // Output status message
  printf("\nTesting your internet speeds...\n");

  // Set random seed
  srand(time(NULL));

  // Generate random download speed within 10% of user input
  double download_speed_rand = download_speed * (1 + (rand() % 21 - 10) / 100.0);
  printf("Random download speed: %f Mbps\n", download_speed_rand);

  // Generate random upload speed within 10% of user input
  double upload_speed_rand = upload_speed * (1 + (rand() % 21 - 10) / 100.0);
  printf("Random upload speed: %f Mbps\n", upload_speed_rand);

  // Generate random latency within 10% of user input
  int latency_rand = latency + (rand() % 21 - 10);
  printf("Random latency: %d milliseconds\n", latency_rand);

  // Output final message
  printf("\nYour internet speed test is complete!\n");
  printf("Download speed: %f Mbps\n", download_speed_rand);
  printf("Upload speed: %f Mbps\n", upload_speed_rand);
  printf("Latency: %d milliseconds\n", latency_rand);

  return 0;
}