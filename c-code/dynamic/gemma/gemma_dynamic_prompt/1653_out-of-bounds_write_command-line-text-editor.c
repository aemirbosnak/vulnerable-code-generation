#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = NULL;
    int size = 0;

    // Allocate memory for the buffer
    buffer = malloc(size);

    // Read the input from the user
    char input[1024];
    printf("Enter text: ");
    fgets(input, 1024, stdin);

    // Write the input to the buffer
    size = strlen(input) + 1;
    buffer = realloc(buffer, size);
    strcpy(buffer, input);

    // Print the edited text
    printf("Edited text: \n");
    printf("%s", buffer);

    // Free the memory allocated for the buffer
    free(buffer);

    return 0;
}
