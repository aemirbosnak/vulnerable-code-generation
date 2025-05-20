//FormAI DATASET v1.0 Category: Sorting ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//Define the maximum length of the strings to be sorted
#define MAX_LENGTH 50

//Function to convert the characters in a string to uppercase
void toUpper(char* str)
{
    int i;
    for(i=0; str[i]; i++)
    {
        str[i] = toupper(str[i]);
    }
}

//Function to compare two strings and return the alphabetical order
int compare(const void *x, const void *y)
{
    char* a = (char*) x;
    char* b = (char*) y;
    toUpper(a);
    toUpper(b);
    return strcmp(a, b);
}

int main()
{
    char** strings; //Array of strings
    int size, i;

    //Get the number of strings to be sorted
    printf("Enter the number of strings to be sorted: ");
    scanf("%d", &size);

    //Allocate memory for the array of strings
    strings = (char**) malloc(sizeof(char*) * size);

    //Get the strings to be sorted from the user
    for(i=0; i<size; i++)
    {
        strings[i] = (char*) malloc(sizeof(char) * MAX_LENGTH);
        printf("Enter string #%d: ", i+1);
        scanf("%s", strings[i]);
    }

    //Sort the array of strings
    qsort(strings, size, sizeof(char*), compare);

    //Print the sorted array of strings
    printf("\nSorted Strings:\n");
    for(i=0; i<size; i++)
    {
        printf("%s\n", strings[i]);
    }

    //Free the memory allocated for the array of strings
    for(i=0; i<size; i++)
    {
        free(strings[i]);
    }
    free(strings);

    return 0;
}