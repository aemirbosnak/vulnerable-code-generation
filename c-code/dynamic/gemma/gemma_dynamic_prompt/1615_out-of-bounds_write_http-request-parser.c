#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char *buffer = malloc(1024);
    char *ptr = buffer;

    // Get the request line
    char *line = getline(&ptr, NULL, stdin);

    // Allocate memory for the header
    char **headers = malloc(1024 * sizeof(char *));

    // Parse the header
    char *header = strtok(line, ":");
    while (header)
    {
        headers[0] = strdup(header);
        header = strtok(NULL, ":");
    }

    // Print the headers
    for (int i = 0; headers[i] != NULL; i++)
    {
        printf("%s: %s\n", headers[i], headers[i + 1]);
    }

    free(buffer);
    free(headers);

    return 0;
}
