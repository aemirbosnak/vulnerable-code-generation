//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int main()
{
    char choice;
    
    printf("*** Welcome to Internet Speed Test Application ***\n");
    
    printf("Please select an option:\n");
    printf("1. Test Download Speed\n");
    printf("2. Test Upload Speed\n");
    scanf("%c", &choice);
    
    if(choice == '1')
    {
        printf("Testing Download Speed...\n");
        
        // Generate random download speed between 1-100 Mbps
        srand(time(NULL)); // Seed random number generator
        int downloadSpeed = rand() % 100 + 1;
        
        // Simulating download speed test
        struct timeval t1, t2;
        gettimeofday(&t1, NULL);
        int i;
        for(i=0;i<1000000000;i++); // Waiting for 1 billion loops
        gettimeofday(&t2, NULL);
        
        // Calculate download time
        double elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
        double downloadTime = elapsedTime / 1000.0; // ms to sec
        
        // Calculate download size in MB
        double downloadSize = (downloadSpeed * downloadTime) / 8; // bits to bytes to MB
        
        printf("Your Download Speed: %.2f Mbps\n", downloadSpeed);
        printf("Download Time: %.2f seconds\n", downloadTime);
        printf("Download Size: %.2f MB\n", downloadSize);
    }
    else if(choice == '2')
    {
        printf("Testing Upload Speed...\n");
        
        // Generate random upload speed between 1-50 Mbps
        srand(time(NULL)); // Seed random number generator
        int uploadSpeed = rand() % 50 + 1;
        
        // Simulating upload speed test
        struct timeval t1, t2;
        gettimeofday(&t1, NULL);
        int i;
        for(i=0;i<500000000;i++); // Waiting for 500 million loops
        gettimeofday(&t2, NULL);
        
        // Calculate upload time
        double elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
        double uploadTime = elapsedTime / 1000.0; // ms to sec
        
        // Calculate upload size in MB
        double uploadSize = (uploadSpeed * uploadTime) / 8; // bits to bytes to MB
        
        printf("Your Upload Speed: %.2f Mbps\n", uploadSpeed);
        printf("Upload Time: %.2f seconds\n", uploadTime);
        printf("Upload Size: %.2f MB\n", uploadSize);
    }
    else
    {
        printf("Invalid Choice. Please select 1 or 2.\n");
    }
    
    return 0;
}