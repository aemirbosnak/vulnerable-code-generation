#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int i = 0;
    int read_size = 0;

    printf("Enter text: ");

    // Loop to read text until the user enters a newline character or the buffer is full
    while (!read_size && !feof(stdin))
    {
        char ch = getchar();
        buffer[i++] = ch;
        read_size++;
    }

    // Print the text that was entered
    printf("Your text: ");
    puts(buffer);

    return 0;
}
