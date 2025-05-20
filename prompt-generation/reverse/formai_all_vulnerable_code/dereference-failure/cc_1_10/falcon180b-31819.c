//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    char input_buffer[MAX_LINE_LENGTH];
    char *input_line = NULL;
    size_t input_line_size = 0;
    char *temp_unit = NULL;
    double temperature = 0;
    char output_buffer[MAX_LINE_LENGTH];
    const char *output_unit = "C";
    const char *output_format = "%.2f %s\n";
    
    // Get input from command line
    if (argc > 1) {
        input_line = argv[1];
        input_line_size = strlen(input_line);
    } else {
        fprintf(stderr, "No input provided. Please enter a temperature value followed by a unit (C, F, K).\n");
        return 1;
    }
    
    // Copy input to buffer
    if (input_line_size >= MAX_LINE_LENGTH) {
        fprintf(stderr, "Input is too long. Maximum length is %d characters.\n", MAX_LINE_LENGTH);
        return 1;
    }
    strcpy(input_buffer, input_line);
    
    // Parse temperature and unit from input
    char *endptr;
    temperature = strtod(input_buffer, &endptr);
    if (endptr == input_buffer) {
        fprintf(stderr, "Invalid temperature value.\n");
        return 1;
    }
    temp_unit = endptr;
    if (strcmp(temp_unit, "C")!= 0 && strcmp(temp_unit, "F")!= 0 && strcmp(temp_unit, "K")!= 0) {
        fprintf(stderr, "Invalid temperature unit. Please use C, F, or K.\n");
        return 1;
    }
    
    // Convert temperature to Celsius
    if (strcmp(temp_unit, "F") == 0) {
        temperature -= 32;
        temperature *= 5.0 / 9.0;
        output_unit = "C";
    } else if (strcmp(temp_unit, "K") == 0) {
        temperature -= 273.15;
        output_unit = "C";
    }
    
    // Format output
    snprintf(output_buffer, MAX_LINE_LENGTH, output_format, temperature, output_unit);
    
    // Print output
    printf("%s", output_buffer);
    
    return 0;
}