//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void main() {
    int i = 0, n = 0, choice = 0;
    char name[20], password[20];
    FILE *fp;

    fp = fopen("digital_diary.txt", "r");
    if (fp == NULL) {
        fp = fopen("digital_diary.txt", "w");
    }

    printf("Welcome to the Digital Diary!\n");
    printf("Please choose an option:\n");
    printf("1. Register\n");
    printf("2. Login\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter your name: ");
            scanf("%s", name);
            printf("Enter your password: ");
            scanf("%s", password);
            fprintf(fp, "%s %s\n", name, password);
            printf("Account created successfully.\n");
            break;
        case 2:
            printf("Enter your name: ");
            scanf("%s", name);
            printf("Enter your password: ");
            scanf("%s", password);
            i = 0;
            while (!strcmp(name, "")) {
                n = fscanf(fp, "%s %s\n", name, password);
                if (n == 2) {
                    if (strcmp(password, "") == 0) {
                        printf("You are logged in.\n");
                        break;
                    }
                }
                i++;
            }
            if (i == 0) {
                printf("Account not found.\n");
            }
            break;
    }

    fclose(fp);
    return;
}