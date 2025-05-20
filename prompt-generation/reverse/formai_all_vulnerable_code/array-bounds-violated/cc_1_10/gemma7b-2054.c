//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, j, xml_start = 0, xml_end = 0, state = 0;
    char tag_name[256];

    printf("Enter XML data: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        switch (state)
        {
            case 0:
                if (buffer[i] == '<')
                {
                    xml_start = i;
                    state = 1;
                }
                break;
            case 1:
                if (buffer[i] == '>')
                {
                    xml_end = i;
                    state = 2;
                    tag_name[xml_start - xml_end - 1] = '\0';
                    printf("Tag name: %s\n", tag_name);
                }
                else if (buffer[i] == '/')
                {
                    state = 0;
                }
                else
                {
                    state = 1;
                }
                break;
            case 2:
                if (buffer[i] == '}')
                {
                    state = 0;
                }
                break;
        }
    }

    return 0;
}