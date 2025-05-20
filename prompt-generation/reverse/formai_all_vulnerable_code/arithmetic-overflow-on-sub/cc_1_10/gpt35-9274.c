//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#define MAXMATCH 50
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    regex_t pattern;
    char line[MAXLINE];
    size_t nmatch = MAXMATCH;
    regmatch_t matches[MAXMATCH];

    // Compile the regular expression pattern
    int ret = regcomp(&pattern, "([A-Za-z]+), ([A-Za-z]+)\n([A-Za-z]+)@(.+)\n([A-Za-z ]+), ([A-Za-z]+)\n(\\d{3}-\\d{2}-\\d{4})", REG_EXTENDED);
    if (ret != 0) {
        printf("Error compiling regular expression.\n");
        exit(1);
    }

    // Open the resume file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening resume file.\n");
        exit(1);
    }

    // Parse each line of the resume
    while (fgets(line, MAXLINE, fp) != NULL) {
        ret = regexec(&pattern, line, nmatch, matches, 0);

        if (ret == 0) {
            // Extract the relevant information
            char name[MAXLINE], email[MAXLINE], street[MAXLINE], city[MAXLINE], state[MAXLINE], zipcode[MAXLINE];
            strncpy(name, line + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so);
            name[matches[1].rm_eo - matches[1].rm_so] = '\0';
            strncpy(name + strlen(name), ", ", 2);
            strncpy(name + strlen(name), line + matches[2].rm_so, matches[2].rm_eo - matches[2].rm_so);
            name[matches[2].rm_eo - matches[2].rm_so + 2] = '\0';
            strncpy(email, line + matches[3].rm_so, matches[3].rm_eo - matches[3].rm_so);
            email[matches[3].rm_eo - matches[3].rm_so] = '\0';
            strncpy(email + strlen(email), "@", 2);
            strncpy(email + strlen(email), line + matches[4].rm_so, matches[4].rm_eo - matches[4].rm_so);
            email[matches[4].rm_eo - matches[4].rm_so + 1] = '\0';
            strncpy(street, line + matches[5].rm_so, matches[5].rm_eo - matches[5].rm_so);
            street[matches[5].rm_eo - matches[5].rm_so] = '\0';
            strncpy(city, line + matches[6].rm_so, matches[6].rm_eo - matches[6].rm_so);
            city[matches[6].rm_eo - matches[6].rm_so] = '\0';
            strncpy(state, line + matches[7].rm_so, 2);
            state[2] = '\0';
            strncpy(zipcode, line + matches[7].rm_so + 3, 5);
            zipcode[5] = '\0';

            // Print the extracted information
            printf("Name: %s\n", name);
            printf("Email: %s\n", email);
            printf("Address: %s, %s, %s %s\n", street, city, state, zipcode);
        }
    }

    // Close file and clean up
    fclose(fp);
    regfree(&pattern);

    return 0;
}