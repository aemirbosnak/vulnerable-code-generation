#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];

    printf("Enter file name: ");
    scanf("%s", buffer);

    FILE *file = fopen(buffer, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Read file contents into the buffer
    size_t read_size = fread(buffer, 1, 1024, file);

    // Print file contents
    printf("File contents:\n");
    printf("%s", buffer);

    fclose(file);
    return 0;
}
