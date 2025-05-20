//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: complete
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

struct Metadata {
    char data_type[MAX_SIZE];
    char variable_name[MAX_SIZE];
    char value[MAX_SIZE];
};

int main()
{
    char code[MAX_SIZE];
    printf("Enter your code:\n");
    fgets(code, MAX_SIZE, stdin);

    struct Metadata metadata_list[MAX_SIZE];
    int metadata_count = 0;

    // Iterating through each line of code to extract metadata
    for(int i=0; code[i]!='\0'; i++) {

        // If data type is found, continue extracting metadata
        if(code[i]=='i' || code[i]=='f' || code[i]=='c' || code[i]=='d') {
            struct Metadata new_metadata;
            int variable_name_index = 0;

            // Extracting data type
            new_metadata.data_type[0] = code[i];
            i++;

            // If it is double data type
            if(code[i]=='o' && code[i+1]=='u' && code[i+2]=='b' && code[i+3]=='l' && code[i+4]=='e') {
                new_metadata.data_type[1] = 'o';
                new_metadata.data_type[2] = 'u';
                new_metadata.data_type[3] = 'b';
                new_metadata.data_type[4] = 'l';
                new_metadata.data_type[5] = 'e';
                i += 4;
            }

            // Extracting variable name
            while(code[i]!='=') {
                // Ignoring any whitespace
                if(code[i]!=' ' && code[i]!='\n') {
                    new_metadata.variable_name[variable_name_index] = code[i];
                    variable_name_index++;
                }
                i++;
            }

            // Extracting value
            int value_index = 0;
            i++;
            while(code[i]!=';' && code[i]!='\n') {
                // Ignoring any whitespace
                if(code[i]!=' ' && code[i]!='\n') {
                    new_metadata.value[value_index] = code[i];
                    value_index++;
                }
                i++;
            }

            // Adding metadata to metadata_list
            metadata_list[metadata_count] = new_metadata;
            metadata_count++;
        }
    }

    // Printing all extracted metadata
    printf("METADATA\n");
    for(int i=0; i<metadata_count; i++) {
        printf("%s %s = %s\n", metadata_list[i].data_type, metadata_list[i].variable_name, metadata_list[i].value);
    }

    return 0;
}