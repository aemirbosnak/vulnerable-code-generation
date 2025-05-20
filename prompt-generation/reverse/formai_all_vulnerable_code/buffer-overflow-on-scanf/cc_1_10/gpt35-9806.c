//FormAI DATASET v1.0 Category: Mailing list manager ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

/*
 * This C program implements a mailing list manager for statistical purposes.
 * It allows users to input email addresses and then perform various statistical analyses on the data.
 * The program is capable of determining the total number of email addresses in the list, calculating the average length
 * of the email address, identifying the longest and shortest email addresses, as well as determining the most frequently
 * occurring domain name within the list of email addresses.
 */

// Function to calculate the average length of the email addresses in the list
float calcAverage(char emailList[MAX][MAX], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += strlen(emailList[i]);
    }

    return (float) sum / (float) count;
}

// Function to identify the longest email address in the list
char* calcLongest(char emailList[MAX][MAX], int count) {
    int maxLength = 0;
    char *longestEmail = malloc(sizeof(char) * MAX);

    for (int i = 0; i < count; i++) {
        if (strlen(emailList[i]) > maxLength) {
            maxLength = strlen(emailList[i]);
            strcpy(longestEmail, emailList[i]);
        }
    }

    return longestEmail;
}

// Function to identify the shortest email address in the list
char* calcShortest(char emailList[MAX][MAX], int count) {
    int minLength = strlen(emailList[0]);
    char *shortestEmail = malloc(sizeof(char) * MAX);

    for (int i = 0; i < count; i++) {
        if (strlen(emailList[i]) < minLength) {
            minLength = strlen(emailList[i]);
            strcpy(shortestEmail, emailList[i]);
        }
    }

    return shortestEmail;
}

// Function to identify the most frequently occurring domain in the list
char* calcMostCommon(char emailList[MAX][MAX], int count) {
    int maxCount = 0;
    char *mostCommon = malloc(sizeof(char) * MAX);

    for (int i = 0; i < count; i++) {
        char *domain = strchr(emailList[i], '@');
        int count = 0;

        for (int j = 0; j < count; j++) {
            if (strstr(emailList[i], domain)) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            strcpy(mostCommon, domain);
        }
    }

    return mostCommon;
}

int main() {
    char email[MAX];
    char emailList[MAX][MAX];
    int count = 0;

    printf("*** Mailing List Manager ***\n");
    printf("Enter email addresses (Type 'exit' to stop):\n");

    while (strcmp(email, "exit") != 0) {
        scanf("%s", email);
        if (strcmp(email, "exit") != 0) {
            strcpy(emailList[count], email);
            count++;
        }
    }

    printf("\nTotal number of email addresses: %d\n", count);

    printf("\nAverage length of email addresses: %.2f\n", calcAverage(emailList, count));

    printf("\nLongest email address: %s\n", calcLongest(emailList, count));

    printf("\nShortest email address: %s\n", calcShortest(emailList, count));

    printf("\nMost common domain: %s\n", calcMostCommon(emailList, count));

    return 0;
}