//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void displayGreeting() {
    printf("🌟 Hello, dear SysAdmin! 🌟\n");
    printf("Welcome to the cheerful system administration tool!\n");
    printf("Let’s keep your system happy and healthy! 🚀\n\n");
}

void checkDiskUsage() {
    printf("📦 Checking disk usage... Please hold on! ⏳\n");
    system("df -h");
    printf("\nAll done with disk usage checks! 😊\n");
}

void listActiveUsers() {
    printf("👥 Checking active users... Hold tight! 🕵️‍♂️\n");
    system("who");
    printf("\nActive users listed! 🎉\n");
}

void displayCurrentTime() {
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    printf("🕒 The current date and time is: %s", asctime(tm_info));
    printf("Time to spread positivity! ✨\n");
}

void displayMenu() {
    printf("🔧 Here’s what I can do for you:\n");
    printf("1. Check Disk Usage\n");
    printf("2. List Active Users\n");
    printf("3. Display Current Date and Time\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    displayGreeting();
    
    while (1) {
        displayMenu();
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkDiskUsage();
                break;
            case 2:
                listActiveUsers();
                break;
            case 3:
                displayCurrentTime();
                break;
            case 4:
                printf("👋 Thank you for using the cheerful SysAdmin tool! Have a great day! 🌈\n");
                exit(0);
            default:
                printf("🚫 Oops! That's not a valid option. Please try again! ✨\n");
                break;
        }
        printf("\n");
    }

    return 0;
}