//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DOWNLOAD_SIZE 1024 * 1024 * 10 // 10 MB
#define UPLOAD_SIZE 1024 * 1024 // 1 MB
#define ITERATIONS 5

double download_speed() {
    int i;
    clock_t start, end;
    double time_used, speed;
    
    printf("Testing download speed...\n");
    
    start = clock(); // Start timer
    
    for (i = 0; i < ITERATIONS; i++) {
        // Simulate download (10 MB file)
        // This would typically be a server request,
        // but for this example we'll just wait
        // for a fixed amount of time
        usleep(DOWNLOAD_SIZE);
    }
    
    end = clock(); // Stop timer
    
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate time elapsed
    speed = (double) DOWNLOAD_SIZE / time_used; // Calculate speed (MB/s)
    
    return speed;
}

double upload_speed() {
    int i;
    clock_t start, end;
    double time_used, speed;
    
    printf("Testing upload speed...\n");
    
    start = clock(); // Start timer
    
    for (i = 0; i < ITERATIONS; i++) {
        // Simulate upload (1 MB file)
        // This would typically be a server request,
        // but for this example we'll just wait
        // for a fixed amount of time
        usleep(UPLOAD_SIZE);
    }
    
    end = clock(); // Stop timer
    
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate time elapsed
    speed = (double) UPLOAD_SIZE / time_used; // Calculate speed (MB/s)
    
    return speed;
}

int main() {
    double download, upload;
    
    download = download_speed();
    upload = upload_speed();
    
    printf("Download speed: %.2f MB/s\n", download);
    printf("Upload speed: %.2f MB/s\n", upload);
    
    return 0;
}