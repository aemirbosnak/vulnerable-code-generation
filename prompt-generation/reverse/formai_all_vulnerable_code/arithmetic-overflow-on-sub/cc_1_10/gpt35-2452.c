//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BUFFER_SIZE 1024
#define MIN_LATENCY 10
#define MAX_LATENCY 100
#define PACKET_SIZE 1024
#define ROUND_TRIP_FACTOR 2.0

float simulate_round_trip(int latency) {
    int data_sent = PACKET_SIZE;
    clock_t send_time = clock();
    clock_t receive_time = send_time + latency * CLOCKS_PER_SEC / 1000;
    float time_elapsed = (receive_time - send_time) / (float)CLOCKS_PER_SEC;
    int data_received = data_sent;
    return data_received / (time_elapsed * ROUND_TRIP_FACTOR);
}

float random_float(float min, float max) {
    return ((float)rand() / RAND_MAX) * (max - min) + min;
}

int main() {
    srand(time(NULL));
    char buffer[BUFFER_SIZE];

    float download_speed = 0.0;
    float upload_speed = 0.0;
    int latency = (int)random_float(MIN_LATENCY, MAX_LATENCY);

    printf("Testing download speed... average of 3 measurements\n");
    for (int i = 0; i < 3; ++i) {
        float speed = simulate_round_trip(latency);
        download_speed = i == 0 ? speed : (download_speed + speed) / 2.0;
        printf("Download speed: %.2f Mbps\n", download_speed);
    }

    latency = (int)random_float(MIN_LATENCY, MAX_LATENCY);
    printf("Testing upload speed... average of 3 measurements\n");
    for (int i = 0; i < 3; ++i) {
        float speed = simulate_round_trip(latency);
        upload_speed = i == 0 ? speed : (upload_speed + speed) / 2.0;
        printf("Upload speed: %.2f Mbps\n", upload_speed);
    }

    printf("Latency: %d ms\n", latency);
    printf("Download speed: %.2f Mbps\n", download_speed);
    printf("Upload speed: %.2f Mbps\n", upload_speed);

    return 0;
}