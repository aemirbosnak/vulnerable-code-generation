//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_download_speed() {
    printf("Testing Download Speed...\n");
    int result = system("curl -s -o /dev/null http://speed.hetzner.de/100MB.bin");
    if (result == -1) {
        perror("Failed to execute curl");
    } else {
        printf("Download Speed Test completed! Check the output above.\n");
    }
}

void test_latency() {
    printf("Testing Latency...\n");
    int result = system("ping -c 4 google.com");
    if (result == -1) {
        perror("Failed to execute ping");
    } else {
        printf("Latency Test completed! Check the output above.\n");
    }
}

void display_menu() {
    printf("***** Internet Speed Test Application *****\n");
    printf("1. Test Download Speed\n");
    printf("2. Test Latency\n");
    printf("3. Exit\n");
    printf("********************************************\n");
}

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                test_download_speed();
                break;
            case 2:
                test_latency();
                break;
            case 3:
                printf("Exiting the application. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}