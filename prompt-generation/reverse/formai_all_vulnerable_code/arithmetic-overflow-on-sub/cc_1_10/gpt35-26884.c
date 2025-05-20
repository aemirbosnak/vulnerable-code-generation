//FormAI DATASET v1.0 Category: Data mining ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Declare variables
    int num_of_records, num_of_attributes, attr_to_search;
    char **attribute_names, **record_names;
    float **data_matrix;
    float search_value;

    // Take user input for number of records, attributes and attribute to search
    printf("Enter number of records: ");
    scanf("%d", &num_of_records);

    printf("Enter number of attributes: ");
    scanf("%d", &num_of_attributes);

    attribute_names = (char **) malloc(num_of_attributes * sizeof(char *));
    for(int i=0; i<num_of_attributes; i++) {
        attribute_names[i] = (char *) malloc(20 * sizeof(char));
        printf("Enter name of attribute %d: ", i+1);
        scanf("%s", attribute_names[i]);
    }

    record_names = (char **) malloc(num_of_records * sizeof(char *));
    for(int i=0; i<num_of_records; i++) {
        record_names[i] = (char *) malloc(20 * sizeof(char));
        printf("Enter name of record %d: ", i+1);
        scanf("%s", record_names[i]);
    }

    data_matrix = (float **) malloc(num_of_records * sizeof(float *));
    for(int i=0; i<num_of_records; i++) {
        data_matrix[i] = (float *) malloc(num_of_attributes * sizeof(float));
        for(int j=0; j<num_of_attributes; j++) {
            printf("Enter value of %s for %s: ", attribute_names[j], record_names[i]);
            scanf("%f", &data_matrix[i][j]);
        }
    }

    printf("Enter attribute to search (1-%d): ", num_of_attributes);
    scanf("%d", &attr_to_search);

    printf("Enter value to search for: ");
    scanf("%f", &search_value);

    printf("Records with %s = %f:\n", attribute_names[attr_to_search-1], search_value);
    for(int i=0; i<num_of_records; i++) {
        if(data_matrix[i][attr_to_search-1] == search_value) {
            printf("%s\n", record_names[i]);
        }
    }

    // Free memory
    for(int i=0; i<num_of_records; i++) {
        free(data_matrix[i]);
        free(record_names[i]);
    }
    for(int i=0; i<num_of_attributes; i++) {
        free(attribute_names[i]);
    }
    free(data_matrix);
    free(record_names);
    free(attribute_names);

    return 0;
}