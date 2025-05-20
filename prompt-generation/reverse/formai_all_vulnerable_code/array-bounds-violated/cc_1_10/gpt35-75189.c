//FormAI DATASET v1.0 Category: Log analysis ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char log[100][1000]; // array to store log entries
    int num_entries; // number of log entries
    int lines = 0; // number of lines in each log entry
    int max_lines = 0; // maximum number of lines in any log entry
    int longest_entry_index; // index of log entry with maximum number of lines
    int i, j; // loop counters

    printf("\nEnter number of log entries: ");
    scanf("%d", &num_entries);

    // read log entries from user
    for (i = 0; i < num_entries; i++)
    {
        printf("\nEnter log entry %d:\n", i+1);
        fgets(log[i], 1000, stdin); // read entire line
        lines = 1; // reset line count
        
        // count number of lines in log entry
        for (j = 0; log[i][j] != '\0'; j++)
        {
            if (log[i][j] == '\n')
            {
                lines++;
            }
        }

        if (lines > max_lines) // check if current entry has most number of lines
        {
            max_lines = lines;
            longest_entry_index = i;
        }
  
    }

    // print log entry with most number of lines
    printf("\nLog entry with maximum number of lines:\n\n");
    for (i = 0; log[longest_entry_index][i] != '\0'; i++) // loop through characters in longest entry
    {
        if (log[longest_entry_index][i] != '\n') // print characters except newlines
        {
            printf("%c", log[longest_entry_index][i]);
        }
        else // if newline encountered, print newline and TAB for indentation
        {
            printf("\n\t");
        }
    }

    return 0;
}