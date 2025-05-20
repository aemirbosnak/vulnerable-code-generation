//FormAI DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_FILE "MyDigitalDiary.txt" // The name of the file we will be using

int main() {
    FILE *fp;
    char entry[1000], ch;
    time_t t = time(NULL); // Getting the current time
    struct tm *tm = localtime(&t); // Converting to local time

    fp = fopen(DIARY_FILE, "a"); // Opening the file to append mode

    if(fp == NULL) { // Checking if the file exists and is accessible
        printf("Error: Could not open file: %s\n", DIARY_FILE);
        exit(1);
    }

    printf("Welcome to your Digital Diary!\n");
    printf("Please enter your diary entry for today:\n");
    scanf("%[^\n]%*c", entry); // Reading the entire line upto '\n' character
    fprintf(fp, "\n\nEntry for Date: %d/%02d/%02d\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    fprintf(fp, "%s\n", entry); // Writing the entry to the file

    printf("\nYour entry has been successfully saved in your Digital Diary!\n");
    printf("Would you like to see your recent entries? (y/n): ");
    scanf("%c", &ch);

    if(ch == 'y' || ch == 'Y') { // Displaying recent entries
        printf("\nRecent entries:\n\n");

        fclose(fp); // Closing the file in append mode

        fp = fopen(DIARY_FILE, "r"); // Opening the file in read mode

        if(fp == NULL) { // Checking if the file exists and is accessible
            printf("Error: Could not open file: %s\n", DIARY_FILE);
            exit(1);
        }

        int count = 0;
        char recentEntry[1000];
        while(fgets(recentEntry, sizeof recentEntry, fp) != NULL) { // Reading the file line-by-line
            if(strncmp(recentEntry, "\n\n", strlen("\n\n")) == 0) { // Checking if the line starts with "\n\n"
                count++;
                if(count <= 5) { // Displaying only the 5 most recent entries
                    printf("%s", recentEntry);
                }
            }
        }

        fclose(fp); // Closing the file in read mode
    } else {
        fclose(fp); // Closing the file in append mode
    }

    return 0;
}