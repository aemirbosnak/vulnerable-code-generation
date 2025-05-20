//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024  // Size of the data buffer
#define TEST_DURATION 5   // Duration in seconds for each test

void display_shape(const char *shape) {
    printf("\n%s...\n\n", shape);
    fflush(stdout);
    usleep(500000); // Sleep for 500ms for a smooth transition
}

void simulate_download() {
    char *shapes[] = {
        "🌐", "🔄", "⚡", "📶"
    };
    
    for (int i = 0; i < 4; i++) {
        display_shape(shapes[i]);
    }
}

void simulate_upload() {
    char *shapes[] = {
        "📤", "📤🔄", "⚙️", "🚀"
    };
    
    for (int i = 0; i < 4; i++) {
        display_shape(shapes[i]);
    }
}

double calculate_speed(size_t data_size, double duration) {
    return (data_size / (duration * 1024.0)); // Speed in KB/s
}

void perform_speed_test() {
    char buffer[BUFFER_SIZE];
    size_t total_downloaded = 0, total_uploaded = 0;
    
    printf("Starting Download Speed Test...\n");
    clock_t start_time = clock();
    
    simulate_download();
    sleep(TEST_DURATION); // Simulate download duration
    total_downloaded = TEST_DURATION * BUFFER_SIZE; // Simulated downloaded data
    
    clock_t end_time = clock();
    double download_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    double download_speed = calculate_speed(total_downloaded, download_time);
    printf("Download Speed: %.2f KB/s\n", download_speed);

    printf("Starting Upload Speed Test...\n");
    start_time = clock();
    
    simulate_upload();
    sleep(TEST_DURATION); // Simulate upload duration
    total_uploaded = TEST_DURATION * BUFFER_SIZE; // Simulated uploaded data
    
    end_time = clock();
    double upload_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    double upload_speed = calculate_speed(total_uploaded, upload_time);
    printf("Upload Speed: %.2f KB/s\n", upload_speed);
}

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");
    perform_speed_test();
    
    printf("Thank you for using the Internet Speed Test Application!\n");
    return 0;
}