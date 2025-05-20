//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 65536
#define TEST_COUNT 5

char host[1024];
char buffer[MAX_BUFFER_SIZE];

// function to generate random data
void generate_random_data() {
    srand((unsigned)time(NULL));
    for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
        buffer[i] = 'a' + (char)(rand() % 26);
    }
}

// function to test internet speed
void test_speed() {
    FILE *fp;
    long speed[TEST_COUNT];
    int total_speed = 0;
    char command[1024];
    sprintf(command, "ping -c 10 %s | grep 'avg' | awk '{print $4}'", host);
    fp = popen(command, "r");

    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    // read output of command and calculate average internet speed
    for (int i = 0; i < TEST_COUNT; i++) {
        char result[1024];
        fgets(result, sizeof(result)-1, fp);
        speed[i] = atof(result);
        total_speed += speed[i];
        printf("Ping time %d is %ld ms\n", (i+1), speed[i]);
        usleep(1000000);
    }

    // calculate average speed
    int avg_speed = total_speed / TEST_COUNT;
    printf("Average Ping time is %d ms\n", avg_speed);
    if (avg_speed < 50) {
        printf("Super fast internet! \n");
    } else if (avg_speed >=50 && avg_speed < 100) {
        printf("Good internet speed!\n");
    } else if (avg_speed >= 100 && avg_speed < 150) {
        printf("Average internet speed\n");
    } else {
        printf("Poor internet speed\n");
    }
}

int main() {
    printf("Enter the name of the host to test internet speed: ");
    scanf("%s", host);
    printf("Testing internet speed for host %s...\n", host);
    generate_random_data();
    test_speed();
    return 0;
}