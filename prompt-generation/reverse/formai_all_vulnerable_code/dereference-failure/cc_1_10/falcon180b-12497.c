//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 20

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *keywords[MAX_KEYWORDS];
    int num_keywords = 0;

    // Initialize our keywords array
    keywords[num_keywords++] = "password";
    keywords[num_keywords++] = "admin";
    keywords[num_keywords++] = "root";
    keywords[num_keywords++] = "login";
    keywords[num_keywords++] = "authentication";
    keywords[num_keywords++] = "authorization";
    keywords[num_keywords++] = "security";
    keywords[num_keywords++] = "breach";
    keywords[num_keywords++] = "attack";
    keywords[num_keywords++] = "vulnerability";

    // Open the log file
    fp = fopen("log.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open log file\n");
        exit(1);
    }

    // Read each line in the log file
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        // Check for keywords in the line
        int i;
        for (i = 0; i < num_keywords; i++) {
            char *keyword = keywords[i];
            char *pos = strstr(line, keyword);
            while (pos!= NULL) {
                // Keyword found!
                printf("Intrusion detected! Keyword '%s' found in line:\n%s\n", keyword, line);
                exit(1);
            }
        }
    }

    // No intrusion detected
    printf("No intrusion detected in log file.\n");
    exit(0);
}