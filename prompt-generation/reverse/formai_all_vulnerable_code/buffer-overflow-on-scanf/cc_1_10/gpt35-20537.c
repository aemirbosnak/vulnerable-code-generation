//FormAI DATASET v1.0 Category: File handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int shape_shift = 0;
    char filename[30], input[100], output[100];

    printf("Welcome to Shape-Shifting File Handling Program!\n");

    while (shape_shift != 4) {
        printf("\nWhat shape do you want the file to take?\n");
        printf(" 1. Rectangle\n 2. Triangle\n 3. Circle\n 4. Exit\n");
        printf("Enter a number: ");
        scanf("%d", &shape_shift);

        switch (shape_shift) {
            case 1:
                // Rectangle
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter text input: ");
                scanf("%s", input);

                // Write to file
                FILE *rectangle_file = fopen(filename, "w");
                fprintf(rectangle_file, "******************************\n");
                fprintf(rectangle_file, "*                            *\n");
                fprintf(rectangle_file, "*          %s           *\n", input);
                fprintf(rectangle_file, "*                            *\n");
                fprintf(rectangle_file, "******************************\n");
                fclose(rectangle_file);

                // Read from file
                FILE *rectangle_file_read = fopen(filename, "r");
                fgets(output, 100, rectangle_file_read);
                printf("\n%s", output);
                fclose(rectangle_file_read);
                break;

            case 2:
                // Triangle
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter text input: ");
                scanf("%s", input);

                // Write to file
                FILE *triangle_file = fopen(filename, "w");
                fprintf(triangle_file, "         %s         \n", input);
                fprintf(triangle_file, "        %s%s%s\n", "<", "^", ">");
                fprintf(triangle_file, "       %s%s%s%s%s\n", "<", "=", "=", "=", ">");
                fclose(triangle_file);

                // Read from file
                FILE *triangle_file_read = fopen(filename, "r");
                fgets(output, 100, triangle_file_read);
                printf("\n%s", output);
                fclose(triangle_file_read);
                break;

            case 3:
                // Circle
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter text input: ");
                scanf("%s", input);

                // Write to file
                FILE *circle_file = fopen(filename, "w");
                fprintf(circle_file, "           %s\n", input);
                fprintf(circle_file, "        /        \\ \n");
                fprintf(circle_file, "      /            \\ \n");
                fprintf(circle_file, "    |                 |\n");
                fprintf(circle_file, "   |                   |\n");
                fprintf(circle_file, "   |                   |\n");
                fprintf(circle_file, "    |                 |\n");
                fprintf(circle_file, "      \\           /\n");
                fprintf(circle_file, "        \\      /\n");
                fprintf(circle_file, "           %s\n", "V");
                fclose(circle_file);

                // Read from file
                FILE *circle_file_read = fopen(filename, "r");
                fgets(output, 100, circle_file_read);
                printf("\n%s", output);
                fclose(circle_file_read);
                break;

            case 4:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}