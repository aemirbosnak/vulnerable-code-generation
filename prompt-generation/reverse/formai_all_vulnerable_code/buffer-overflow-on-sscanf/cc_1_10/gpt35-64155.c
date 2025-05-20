//FormAI DATASET v1.0 Category: System boot optimizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

#define true 1
#define false 0

typedef unsigned char bool;

void optimize_boot_sequence(char *input_file_path, char *output_file_path);

int main()
{
    optimize_boot_sequence("boot_input.txt", "boot_output.txt");
    return 0;
}

void optimize_boot_sequence(char *input_file_path, char *output_file_path)
{
    // Open the input file for reading
    FILE *input_file = fopen(input_file_path, "r");

    // If the input file did not open successfully, exit the program
    if (input_file == NULL)
    {
        printf("Error: Failed to open input file %s.\n", input_file_path);
        exit(EXIT_FAILURE);
    }

    // Open the output file for writing
    FILE *output_file = fopen(output_file_path, "w");

    // If the output file did not open successfully, exit the program
    if (output_file == NULL)
    {
        printf("Error: Failed to open output file %s.\n", output_file_path);
        exit(EXIT_FAILURE);
    }

    // Initialize a buffer to read lines from the input file
    char line_buffer[MAX_LINE_LENGTH];

    // Initialize a variable to store the number of lines read
    int line_count = 0;

    // Read lines from the input file and write them to the output file
    while (fgets(line_buffer, MAX_LINE_LENGTH, input_file) != NULL)
    {
        line_count++;

        // Check if the line is a comment or an empty line
        // If it is, write it to the output file as-is
        if (line_buffer[0] == '#' || line_buffer[0] == '\n')
        {
            fputs(line_buffer, output_file);
            continue;
        }

        // Parse the line to extract the boot sequence program
        char boot_program[MAX_LINE_LENGTH];
        int success = sscanf(line_buffer, "BOOT %s", boot_program);

        // If the line was not parsed successfully, write it to the output file and continue
        if (success != 1)
        {
            fputs(line_buffer, output_file);
            continue;
        }

        // Open the boot program file for reading
        char boot_program_file_path[MAX_LINE_LENGTH];
        sprintf(boot_program_file_path, "%s.bin", boot_program);
        FILE *boot_program_file = fopen(boot_program_file_path, "rb");

        // If the boot program file did not open successfully, write an error message to the output file and continue
        if (boot_program_file == NULL)
        {
            fprintf(output_file, "Error: Failed to open boot program %s.\n", boot_program);
            continue;
        }

        // Determine the size of the boot program file
        fseek(boot_program_file, 0L, SEEK_END);
        int boot_program_size = ftell(boot_program_file);
        fseek(boot_program_file, 0L, SEEK_SET);

        // Allocate a buffer to read the boot program file
        char *boot_program_buffer = (char *) malloc(boot_program_size);

        // Read the boot program file into the buffer
        int bytes_read = fread(boot_program_buffer, sizeof(char), boot_program_size, boot_program_file);

        // If not all bytes were read from the file, write an error message to the output file and continue
        if (bytes_read != boot_program_size)
        {
            fprintf(output_file, "Error: Failed to read boot program %s.\n", boot_program);
            free(boot_program_buffer);
            fclose(boot_program_file);
            continue;
        }

        // Check if the boot program is optimized already
        bool is_optimized = true;
        for (int i = 0; i < boot_program_size; i++)
        {
            if (boot_program_buffer[i] != 0x90)
            {
                is_optimized = false;
                break;
            }
        }

        // If the program is already optimized, write a message to the output file and continue
        if (is_optimized)
        {
            fprintf(output_file, "Boot program %s is already optimized.\n", boot_program);
            free(boot_program_buffer);
            fclose(boot_program_file);
            continue;
        }

        // Optimize the boot program and write it to a new file
        char optimized_boot_program_file_path[MAX_LINE_LENGTH];
        sprintf(optimized_boot_program_file_path, "%s_opt.bin", boot_program);
        FILE *optimized_boot_program_file = fopen(optimized_boot_program_file_path, "wb");

        // If the optimized boot program file did not open successfully, write an error message to the output file and continue
        if (optimized_boot_program_file == NULL)
        {
            fprintf(output_file, "Error: Failed to create optimized boot program %s_opt.bin.\n", boot_program);
            free(boot_program_buffer);
            fclose(boot_program_file);
            continue;
        }

        // Write the optimized boot program to the new file
        int zeroes_written = 0;
        for (int i = 0; i < boot_program_size; i++)
        {
            if (boot_program_buffer[i] == 0x00)
            {
                // Write a single zero byte instead of a series of zero bytes
                if (zeroes_written == 0)
                {
                    fputc(0x00, optimized_boot_program_file);
                }
                zeroes_written++;
            }
            else
            {
                zeroes_written = 0;
                fputc(boot_program_buffer[i], optimized_boot_program_file);
            }
        }

        // Close the optimized boot program file
        fclose(optimized_boot_program_file);

        // Write an optimization message to the output file
        fprintf(output_file, "Optimized boot program %s from %d bytes to %d bytes.\n", boot_program, boot_program_size, boot_program_size - zeroes_written);

        // Free the boot program buffer
        free(boot_program_buffer);

        // Close the boot program file
        fclose(boot_program_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);
}