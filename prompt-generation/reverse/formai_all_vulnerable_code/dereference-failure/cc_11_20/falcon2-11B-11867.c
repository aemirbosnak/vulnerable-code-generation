//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
    // Check for correct usage
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }
    
    // Open input file
    FILE *in_file = fopen(argv[1], "r");
    if (in_file == NULL) {
        fprintf(stderr, "Error opening input file\n");
        return 2;
    }
    
    // Open output file
    FILE *out_file = fopen(argv[2], "w");
    if (out_file == NULL) {
        fprintf(stderr, "Error opening output file\n");
        fclose(in_file);
        return 3;
    }
    
    // Read header line
    char header[256];
    if (fgets(header, sizeof(header), in_file) == NULL) {
        fprintf(stderr, "Error reading header line\n");
        fclose(in_file);
        fclose(out_file);
        return 4;
    }
    
    // Read and write each row
    char line[256];
    char delimiter = ',';
    int num_fields = 0;
    while (fgets(line, sizeof(line), in_file)!= NULL) {
        char *field;
        char *value;
        
        // Split line into fields
        for (field = strtok(line, &delimiter); field!= NULL; field = strtok(NULL, &delimiter)) {
            // Skip empty fields
            if (strlen(field) == 0)
                continue;
            
            // Convert field to lowercase
            char *lower_field = strdup(field);
            for (int i = 0; i < strlen(lower_field); i++)
                lower_field[i] = tolower(lower_field[i]);
            
            // Check if field is a number
            if (isdigit(lower_field[0])) {
                // Convert field to integer
                int value_int;
                sscanf(field, "%d", &value_int);
                
                // Print field in formatted output
                fprintf(out_file, "%s = %d\n", lower_field, value_int);
            } else {
                // Print field in unformatted output
                fprintf(out_file, "%s = %s\n", lower_field, field);
            }
            
            // Increase field count
            num_fields++;
        }
        
        // Write separator line
        if (num_fields > 0)
            fprintf(out_file, "--------------------\n");
    }
    
    // Close files
    fclose(in_file);
    fclose(out_file);
    
    return 0;
}