//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Romeo and Juliet
#include <stdio.h>

#define MAX_LINE 1024
#define MAX_WORD 64
#define MAX_PATTERN 64
#define MAX_FILE 100

char pattern[MAX_PATTERN];
char file_name[MAX_FILE];

// function to search pattern in the file
int search_pattern(FILE *fp)
{
    char line[MAX_LINE];
    char word[MAX_WORD];
    int count = 0;

    while (fgets(line, MAX_LINE, fp)!= NULL)
    {
        char *p = strtok(line, " ");
        while (p!= NULL)
        {
            // copy word to lowercase
            strcpy(word, p);
            for (int i = 0; i < strlen(word); i++)
            {
                word[i] = tolower(word[i]);
            }
            // check if pattern is present in word
            if (strstr(word, pattern)!= NULL)
            {
                count++;
                break;
            }
            p = strtok(NULL, " ");
        }
    }

    return count;
}

// function to read pattern from user
void read_pattern()
{
    printf("Enter pattern to search: ");
    scanf("%s", pattern);
}

// function to read file name from user
void read_file_name()
{
    printf("Enter file name: ");
    scanf("%s", file_name);
}

// main function
int main()
{
    read_pattern();
    read_file_name();

    // open file for reading
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("Error opening file %s\n", file_name);
        return 1;
    }

    // search pattern in the file
    int count = search_pattern(fp);

    // close file
    fclose(fp);

    if (count == 0)
    {
        printf("Pattern not found in file %s\n", file_name);
    }
    else
    {
        printf("Pattern found %d times in file %s\n", count, file_name);
    }

    return 0;
}