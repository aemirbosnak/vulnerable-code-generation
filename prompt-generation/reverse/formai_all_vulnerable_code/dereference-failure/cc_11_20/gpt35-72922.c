//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 1000

int main()
{
    char input[MAX_STRING_SIZE];
    printf("Enter XML input: ");
    fgets(input, MAX_STRING_SIZE, stdin);

    char* tag_name = NULL;
    char* tag_attr_name = NULL;
    char* tag_attr_value = NULL;

    bool in_tag = false;
    bool in_attr = false;
    bool in_attr_value = false;

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '<')
        {
            in_tag = true;
            tag_name = malloc(MAX_STRING_SIZE * sizeof(char));
            memset(tag_name, 0, MAX_STRING_SIZE);
        }
        else if (input[i] == '>')
        {
            in_tag = false;
            printf("Found tag: <%s>\n", tag_name);
            free(tag_name);
        }
        else if (in_tag)
        {
            if (input[i] == ' ')
            {
                in_attr = true;
                tag_attr_name = malloc(MAX_STRING_SIZE * sizeof(char));
                memset(tag_attr_name, 0, MAX_STRING_SIZE);
            }
            else if (input[i] == '=')
            {
                in_attr_value = true;
            }
            else if (input[i] == '"')
            {
                if (in_attr_value)
                {
                    in_attr_value = false;
                    printf("Found attribute: %s='%s'\n", tag_attr_name, tag_attr_value);
                    free(tag_attr_name);
                    free(tag_attr_value);
                }
            }
            else
            {
                if (in_attr)
                {
                    if (!in_attr_value)
                    {
                        tag_attr_value = malloc(MAX_STRING_SIZE * sizeof(char));
                        memset(tag_attr_value, 0, MAX_STRING_SIZE);
                    }
                    else
                    {
                        size_t attr_value_len = strlen(tag_attr_value);
                        tag_attr_value[attr_value_len] = input[i];
                    }
                }
                else
                {
                    size_t tag_name_len = strlen(tag_name);
                    tag_name[tag_name_len] = input[i];
                }
            }
        }
    }

    return 0;
}