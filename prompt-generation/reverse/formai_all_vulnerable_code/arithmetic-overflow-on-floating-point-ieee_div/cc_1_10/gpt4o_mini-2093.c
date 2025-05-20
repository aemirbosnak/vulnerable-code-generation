//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "93.184.216.34"  // Example IP for test
#define PORT 80
#define BUFFER_SIZE 1048576 // 1 MB

void test_internet_speed() {
    char *buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        perror("Failed to allocate buffer");
        return;
    }

    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        free(buffer);
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    int connection = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (connection < 0) {
        perror("Connection to server failed");
        free(buffer);
        close(sockfd);
        return;
    }

    printf("Connected to the ocean of data where dreams drift...\n");

    // Start time
    time_t start_time = time(NULL);
    printf("Tides are rising... sending data into the abyss...\n");
    
    ssize_t bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_sent < 0) {
        perror("Send failed");
        free(buffer);
        close(sockfd);
        return;
    }

    // End time
    time_t end_time = time(NULL);
    printf("The sand has slipped through the hourglass. Bytes sent: %ld\n", bytes_sent);
    
    double duration = difftime(end_time, start_time);
    
    printf("It took %lf seconds to send the data.\n", duration);
    double speed_mbps = (bytes_sent / duration) * 8 / (1024 * 1024); // Convert bytes to Mbps
    
    printf("The ethereal speed of your dreams: %.2f Mbps\n", speed_mbps);

    free(buffer);
    close(sockfd);
}

int main() {
    printf("As the clock melts into the ether, we embark on a quest...\n");
    printf("An internet speed test, a dance with packets and bytes...\n");

    while (1) {
        test_internet_speed();
        printf("Do you wish to test the sands of connectivity again? (yes/no): ");
        char answer[4];
        scanf("%3s", answer);
        if (strcmp(answer, "no") == 0) {
            printf("The journey ends here, as shadows blend with light...\n");
            break;
        }
        printf("The cycle repeats...\n");
        sleep(5); // Sleep for a moment, let the surrealism settle
    }

    return 0;
}