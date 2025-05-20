//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {

    FILE *fp;
    char *input_file_path = argv[1];
    char line[MAX_LINE_LENGTH];
    char *token;
    int line_counter = 0;
    int field_counter = 0;
    int paranoid_flag = 0;

    // check if input file exists
    if ((fp = fopen(input_file_path, "r")) == NULL) {
        printf("File '%s' does not exist!\n", input_file_path);
        return -1;
    }

    // parse through each line of the csv file
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        line_counter++;
        char *line_copy = strdup(line);

        // check if line has any extra commas
        char *comma_pos = strchr(line_copy, ',');
        if (comma_pos != NULL) {
            char *comma_pos_last = strrchr(line_copy, ',');
            if (comma_pos != comma_pos_last) {
                char *extra_commas_pos = strstr(line_copy, ",,");
                if (extra_commas_pos != NULL) {
                    paranoid_flag++;
                    printf("Error in line %d: Extra commas found in line\n", line_counter);
                    continue;
                }
            }
        }

        // check if line has any missing fields
        int curr_field_counter = 0;
        token = strtok(line, ",");
        while (token != NULL) {
            curr_field_counter++;
            field_counter++;
            token = strtok(NULL, ",");

            // check if field is empty
            if (strlen(token) == 0) {
                paranoid_flag++;
                printf("Error in line %d: Field %d is empty\n", line_counter, curr_field_counter);
            }
        }

        // check if line has the same number of fields as the first line
        if (line_counter == 1) {
            char *first_line_copy = strdup(line_copy);
            int first_field_count = 0;
            token = strtok(first_line_copy, ",");
            while (token != NULL) {
                first_field_count++;
                token = strtok(NULL, ",");
            }
            if (first_field_count != field_counter) {
                paranoid_flag++;
                printf("Error in line %d: Incorrect number of fields\n", line_counter);
            }
            free(first_line_copy);
        }

        free(line_copy);
    }

    // print summary
    if (paranoid_flag == 0) {
        printf("CSV file '%s' parsed successfully. No errors found.\n", input_file_path);
    } else {
        printf("CSV file '%s' parsed with %d errors. See error messages above.\n", input_file_path, paranoid_flag);
    }

    fclose(fp);
    return 0;
}