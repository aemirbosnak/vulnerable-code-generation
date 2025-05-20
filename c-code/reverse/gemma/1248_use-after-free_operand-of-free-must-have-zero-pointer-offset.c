#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    const int MAX_ENTRIES = 10;
    char entries[MAX_ENTRIES][100];

    // Get user input for diary entries
    for (int i = 0; i < MAX_ENTRIES && scanf("%s %[^\n]", entries[i][0], entries[i][1]) != EOF; i++) {}

    // Display all entries
    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        printf("Title: %s\n", entries[i][0]);
        printf("Content: %s\n", entries[i][1]);
    }

    // Attempt to free memory occupied by each entry (not applicable, as no memory was dynamically allocated)
    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        free(entries[i]); // This line will cause a crash
    }

    return 0;
}
