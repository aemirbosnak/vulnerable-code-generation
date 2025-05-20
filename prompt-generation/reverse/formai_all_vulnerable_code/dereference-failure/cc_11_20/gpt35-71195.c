//FormAI DATASET v1.0 Category: Log analysis ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000    // Maximum size of a line in the log file
#define MAXWORD 100     // Maximum size of a word in the log file
#define MAXCOUNT 1000   // Maximum number of words to count

int main(int argc, char *argv[]) {

    /* Check for correct number of arguments */
    if (argc != 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        exit(1);
    }

    /* Open the log file */
    FILE *logfp;
    if ((logfp = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open file: %s\n", argv[1]);
        exit(1);
    }

    /* Initialize variables */
    char line[MAXLINE], word[MAXWORD];
    int linenum = 0, count = 0, i, j;
    int wordcount[MAXCOUNT] = {0};
    char *wordlist[MAXCOUNT];

    /* Read each line of the log file */
    while (fgets(line, MAXLINE, logfp) != NULL) {
        linenum++;

        /* Split the line into words */
        i = 0;
        while (line[i] != '\0') {

            /* Skip leading white space */
            while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
                i++;
            }

            /* Extract the word */
            j = 0;
            while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\0') {
                word[j] = line[i];
                i++;
                j++;
            }
            word[j] = '\0';

            /* Add the word to the list */
            if (j > 0) {

                /* Check if the word is already in the list */
                int found = 0, k;
                for (k = 0; k < count; k++) {
                    if (strcmp(word, wordlist[k]) == 0) {
                        found = 1;
                        wordcount[k]++;
                        break;
                    }
                }

                /* Add the word to the list if not already there */
                if (!found) {
                    if (count >= MAXCOUNT) {
                        printf("Too many words to count.\n");
                        exit(1);
                    }
                    wordlist[count] = strdup(word);
                    wordcount[count] = 1;
                    count++;
                }
            }
        }
    }

    /* Print the results */
    printf("Word Count: %d\n", count);
    for (i = 0; i < count; i++) {
        printf("%10s : %d\n", wordlist[i], wordcount[i]);
    }

    /* Close the log file */
    fclose(logfp);

    return 0;
}