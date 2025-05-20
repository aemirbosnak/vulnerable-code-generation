//Falcon-180B DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024

/* Function to print error message and exit program */
void error(char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char filename[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];

    /* Check if correct number of arguments are provided */
    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Copy filename argument to a local variable */
    strcpy(filename, argv[1]);

    /* Open the file for reading */
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        error("Error opening file");
    }

    /* Read lines from the file */
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL)
    {
        /* Print the line to stdout */
        printf("%s", line);
    }

    /* Close the file */
    if (fclose(fp)!= 0)
    {
        error("Error closing file");
    }

    return 0;
}