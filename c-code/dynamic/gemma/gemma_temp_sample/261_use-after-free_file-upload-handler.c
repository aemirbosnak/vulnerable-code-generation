#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *file_data = NULL;
    size_t file_size = 0;

    // Allocate memory for file data
    file_data = malloc(1024);

    // Read file data from client
    FILE *fp = fopen("test.txt", "r");
    if (fp)
    {
        fseek(fp, 0, SEEK_SET);
        fread(file_data, 1, file_size, fp);
        fclose(fp);
    }

    // Free memory allocated for file data
    free(file_data);

    // Use freed memory
    printf("%s", file_data);

    return 0;
}
