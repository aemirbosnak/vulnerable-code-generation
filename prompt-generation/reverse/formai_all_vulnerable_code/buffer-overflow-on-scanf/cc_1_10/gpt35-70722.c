//FormAI DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 512
#define HEADER_SIZE 54

void print_menu();
void open_file(char* filename, unsigned char header[], unsigned char pixels[][MAX_SIZE][3]);
void save_file(char* filename, unsigned char header[], unsigned char pixels[][MAX_SIZE][3]);
void apply_filter(unsigned char pixels[][MAX_SIZE][3], int filter[][3], int sz);
void greyscale(unsigned char pixels[][MAX_SIZE][3]);
void invert_colors(unsigned char pixels[][MAX_SIZE][3]);

int main()
{
    char filename[256];
    int option;
    unsigned char header[HEADER_SIZE];
    unsigned char pixels[MAX_SIZE][MAX_SIZE][3];

    printf("Welcome to C Image Editor!\n");

    do {
        print_menu();

        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the filename: ");
                scanf("%s", filename);

                open_file(filename, header, pixels);

                printf("File opened successfully!\n");

                break;
            case 2:
                printf("Enter the filename: ");
                scanf("%s", filename);

                save_file(filename, header, pixels);

                printf("File saved successfully!\n");

                break;
            case 3:
                printf("Applying greyscale filter...\n");

                greyscale(pixels);

                break;
            case 4:
                printf("Inverting colors...\n");

                invert_colors(pixels);

                break;
            case 5:
                printf("Applying custom filter...\n");

                int filter[3][3] = {{-1,-1,-1},{-1,8,-1},{-1,-1,-1}};
                int sz = 3;

                apply_filter(pixels, filter, sz);

                break;
            case 6:
                printf("Exiting...\n");

                break;
            default:
                printf("Invalid option. Try again.\n");

                break;
        }
    } while (option != 6);

    return 0;
}

void print_menu()
{
    printf("Menu:\n");
    printf("1. Open file.\n");
    printf("2. Save file.\n");
    printf("3. Apply greyscale filter.\n");
    printf("4. Invert colors.\n");
    printf("5. Apply custom filter.\n");
    printf("6. Exit.\n");
}

void open_file(char* filename, unsigned char header[], unsigned char pixels[][MAX_SIZE][3])
{
    FILE* fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read header
    fread(header, sizeof(unsigned char), HEADER_SIZE, fp);

    // Read pixels
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            fread(pixels[i][j], sizeof(unsigned char), 3, fp);
        }
    }

    fclose(fp);
}

void save_file(char* filename, unsigned char header[], unsigned char pixels[][MAX_SIZE][3])
{
    FILE* fp = fopen(filename, "wb");

    if (fp == NULL) {
        printf("Error saving file.\n");
        exit(1);
    }

    // Write header
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, fp);

    // Write pixels
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            fwrite(pixels[i][j], sizeof(unsigned char), 3, fp);
        }
    }

    fclose(fp);
}

void apply_filter(unsigned char pixels[][MAX_SIZE][3], int filter[][3], int sz)
{
    int offset = sz / 2;
    unsigned char new_pixels[MAX_SIZE][MAX_SIZE][3];

    for (int i = offset; i < MAX_SIZE - offset; i++) {
        for (int j = offset; j < MAX_SIZE - offset; j++) {
            int sum_r = 0, sum_g = 0, sum_b = 0;

            for (int x = 0; x < sz; x++) {
                for (int y = 0; y < sz; y++) {
                    sum_r += pixels[i - offset + x][j - offset + y][0] * filter[x][y];
                    sum_g += pixels[i - offset + x][j - offset + y][1] * filter[x][y];
                    sum_b += pixels[i - offset + x][j - offset + y][2] * filter[x][y];
                }
            }

            new_pixels[i][j][0] = abs(sum_r);
            new_pixels[i][j][1] = abs(sum_g);
            new_pixels[i][j][2] = abs(sum_b);
        }
    }

    // Update original pixels
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            pixels[i][j][0] = new_pixels[i][j][0];
            pixels[i][j][1] = new_pixels[i][j][1];
            pixels[i][j][2] = new_pixels[i][j][2];
        }
    }
}

void greyscale(unsigned char pixels[][MAX_SIZE][3])
{
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            int avg = (pixels[i][j][0] + pixels[i][j][1] + pixels[i][j][2]) / 3;

            pixels[i][j][0] = avg;
            pixels[i][j][1] = avg;
            pixels[i][j][2] = avg;
        }
    }
}

void invert_colors(unsigned char pixels[][MAX_SIZE][3])
{
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            pixels[i][j][0] = 255 - pixels[i][j][0];
            pixels[i][j][1] = 255 - pixels[i][j][1];
            pixels[i][j][2] = 255 - pixels[i][j][2];
        }
    }
}