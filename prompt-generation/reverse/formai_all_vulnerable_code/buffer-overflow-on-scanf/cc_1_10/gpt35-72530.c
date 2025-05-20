//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void displayMenu() {
    printf("Welcome to the Internet Speed Test Application\n");
    printf("1. Begin test\n");
    printf("2. View test history\n");
    printf("3. Exit\n");
}

int getChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int runSpeedTest() {
    printf("Beginning speed test...\n");
    srand(time(NULL));
    int downloadSpeed = rand() % 20 + 1;
    int uploadSpeed = rand() % 10 + 1;
    printf("Download speed: %d Mbps\n", downloadSpeed);
    printf("Upload speed: %d Mbps\n", uploadSpeed);
    return 1;
}

void viewTestHistory() {
    printf("Test history not available.\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        choice = getChoice();
        switch(choice) {
            case 1:
                runSpeedTest();
                break;
            case 2:
                viewTestHistory();
                break;
            case 3:
                printf("Thank you for using the Internet Speed Test Application!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 3);
    return 0;
}