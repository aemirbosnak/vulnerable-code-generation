//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int user_id;
    char name[30];
    char password[20];
    FILE *fp;
    struct tm date;
    time_t now;
    char ch;

    printf("Welcome to the Digital Diary!\n");
    printf("Please enter your name: ");
    fflush(stdin);
    scanf("%s", name);
    printf("Please enter your ID: ");
    scanf("%d", &user_id);
    printf("Please enter your password: ");
    scanf("%s", password);

    if (user_id == 0) {
        printf("Invalid ID. Please try again.\n");
        return 0;
    }

    fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            if (strcmp(name, "admin") == 0) {
                printf("You are logged in as admin.\n");
                break;
            } else if (strcmp(name, "guest") == 0) {
                printf("You are logged in as guest.\n");
                break;
            } else {
                printf("Invalid ID or password.\n");
                fclose(fp);
                return 0;
            }
        }
    }

    fclose(fp);

    fp = fopen("diary.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    time(&now);
    localtime_r(&now, &date);

    fprintf(fp, "Date: %d-%02d-%02d\n", date.tm_year + 1900, date.tm_mon + 1, date.tm_mday);
    fprintf(fp, "User ID: %d\n", user_id);
    fprintf(fp, "Name: %s\n", name);
    fprintf(fp, "Password: %s\n", password);
    fprintf(fp, "\n");

    printf("Diary entry successfully saved.\n");

    fclose(fp);

    return 0;
}