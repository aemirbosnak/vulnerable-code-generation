//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0, n, original_size, compressed_size;

    printf("Enter the original size of the text: ");
    scanf("%d", &original_size);

    printf("Enter the text: ");
    fgets(buffer, original_size, stdin);

    n = compress(buffer, original_size, &compressed_size);

    printf("The compressed size is: %d", compressed_size);

    if (n)
    {
        printf("The compressed text is: ");
        puts(buffer);
    }

    return 0;
}

int compress(char *buffer, int original_size, int *compressed_size)
{
    int i, j, count = 0, compressed_size_ = 0;
    char *compressed_buffer = NULL;

    for (i = 0; i < original_size; i++)
    {
        char current_char = buffer[i];
        char previous_char = (i > 0) ? buffer[i - 1] : '\0';

        if (current_char == previous_char)
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                compressed_buffer = realloc(compressed_buffer, compressed_size_ + 1);
                compressed_buffer[compressed_size_] = count + 'a';
                compressed_size_++;
            }

            count = 1;
            compressed_buffer = realloc(compressed_buffer, compressed_size_ + 1);
            compressed_buffer[compressed_size_] = current_char;
            compressed_size_++;
        }
    }

    *compressed_size = compressed_size_;

    return count > 1;
}