//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
   int i, j;
   double speed;
   char command[100];

   printf("Welcome to our Internet Speed Test Application!\n");
   printf("Please wait while we prepare the test...\n");

   // Generating random download and upload speeds
   srand(time(0));
   double download_speed = (double)(rand() % 5000 + 500) / 1000.0;
   double upload_speed = (double)(rand() % 1000 + 500) / 1000.0;

   printf("Download speed: %.2lf Mbps\n", download_speed);
   printf("Upload speed: %.2lf Mbps\n", upload_speed);

   // Prompting user to start the test
   printf("\nTo start the test, please type 'start': ");
   scanf("%s", command);
   if (strcmp(command, "start") != 0) {
       printf("Invalid command. Exiting...\n");
       return 0;
   }

   // Downloading a 100MB file
   printf("\nDownloading a 100MB file...\n");
   for (i = 0; i < 100; i++) {
       // Simulating download speed
       for (j = 0; j < (int)(download_speed * 10); j++) {
           // Busy wait
       }
       printf("%02d%% completed\n", i+1);
   }
   printf("\nDownload completed.\n");

   // Uploading a 10MB file
   printf("\nUploading a 10MB file...\n");
   for (i = 0; i < 10; i++) {
       // Simulating upload speed
       for (j = 0; j < (int)(upload_speed * 10); j++) {
           // Busy wait
       }
       printf("%02d%% completed\n", (i+1)*10);
   }
   printf("\nUpload completed.\n");

   // Calculating average speed
   speed = (download_speed + upload_speed) / 2.0;
   printf("\nYour Internet Speed Test is completed.\n");
   printf("Average speed: %.2lf Mbps\n", speed);
   printf("Thank you for using our Internet Speed Test Application!\n");

   return 0;
}