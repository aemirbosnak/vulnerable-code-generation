//Gemma-7B DATASET v1.0 Category: File handling ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main()
{
    FILE* file = NULL;
    char buffer[BUFFER_SIZE] = "";
    int read_size = 0, write_size = 0;
    char command = '\0';

    printf("File Manager\n");
    printf("--------------------\n");

    while (command != 'q')
    {
        printf("Enter command (a/w/r/d/q): ");
        scanf(" %c", &command);

        switch (command)
        {
            case 'a':
                file = fopen("new.txt", "w");
                write_size = 0;
                break;
            case 'w':
                printf("Enter text: ");
                scanf("%[^\n]%*c", buffer);
                write_size = write(file, buffer, BUFFER_SIZE);
                break;
            case 'r':
                file = fopen("new.txt", "r");
                read_size = read(file, buffer, BUFFER_SIZE);
                printf("Read data: %s", buffer);
                break;
            case 'd':
                fclose(file);
                remove("new.txt");
                break;
            case 'q':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        if (file)
        {
            fclose(file);
        }

        if (write_size > 0)
        {
            printf("Write size: %d bytes\n", write_size);
        }

        if (read_size > 0)
        {
            printf("Read size: %d bytes\n", read_size);
        }
    }

    return 0;
}