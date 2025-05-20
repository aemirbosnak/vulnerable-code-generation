//FormAI DATASET v1.0 Category: Text processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to replace all occurrences of a given word in a text file
void findAndReplace(char *fname, char *s1, char *s2)
{
    FILE *fp; // file pointer
    FILE *temp; // temporary file pointer
    char buffer[1000]; // buffer to store each line of file
    char *ptr;

    // open file to read
    fp = fopen(fname, "r");

    // check if file exists
    if (fp == NULL)
    {
        printf("File '%s' does not exist.\n", fname);
        exit(1);
    }

    // create temporary file to write changes
    temp = fopen("temp.txt", "w");

    // loop through each line in the file
    while (fgets(buffer, 1000, fp))
    {
        // replace all occurrences of s1 with s2 in current line
        while ((ptr = strstr(buffer, s1)) != NULL)
        {
            strncpy(ptr, s2, strlen(s2));
            memmove(ptr + strlen(s2), ptr + strlen(s1), strlen(ptr + strlen(s1)) + 1);
        }

        // write line with changes to temporary file
        fputs(buffer, temp);
    }

    // close both files
    fclose(fp);
    fclose(temp);

    // rename temporary file to original file
    rename("temp.txt", fname);

    printf("String '%s' has been replaced with '%s' in file '%s'.\n", s1, s2, fname);
}

int main()
{
    char fname[100]; // name of file to read
    char s1[100]; // word to find
    char s2[100]; // word to replace with
    char choice; // user choice to continue or not

    // loop until user chooses to quit
    do
    {
        // get file name, word to find, and word to replace from user
        printf("Enter name of file to read: ");
        scanf("%s", fname);
        printf("Enter word to find: ");
        scanf("%s", s1);
        printf("Enter word to replace with: ");
        scanf("%s", s2);

        // call function to replace word in file
        findAndReplace(fname, s1, s2);

        // ask user if they want to replace more words in file
        printf("Replace more words? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}