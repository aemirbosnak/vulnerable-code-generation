//FormAI DATASET v1.0 Category: Image Editor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define HEADER_SIZE 54

void print_menu();
void save_changes();
void apply_filter();

char in_filename[MAX_FILENAME_LENGTH];
char out_filename[MAX_FILENAME_LENGTH];
unsigned char *image_data = NULL;
unsigned char *temp_data = NULL;
int width, height, padding, image_size;

int main()
{
    FILE *fp_in, *fp_out;
    unsigned char header[HEADER_SIZE];

    printf("Enter the input filename: ");
    fgets(in_filename, MAX_FILENAME_LENGTH, stdin);
    in_filename[strcspn(in_filename, "\n")] = 0;

    fp_in = fopen(in_filename, "r+b");
    if (fp_in == NULL) {
        printf("Failed to open input file!\n");
        exit(EXIT_FAILURE);
    }

    fread(header, sizeof(unsigned char), HEADER_SIZE, fp_in);
    width = *(int*)&header[18];
    height = *(int*)&header[22];
    int bpp = *(int*)&header[28];
    if (bpp != 24) {
        printf("Invalid input file!\n");
        exit(EXIT_FAILURE);
    }
    padding = (4 - (width * sizeof(unsigned char) * 3) % 4) % 4;
    image_size = height * (width * sizeof(unsigned char) * 3 + padding);

    image_data = (unsigned char*)malloc(image_size);
    temp_data = (unsigned char*)malloc(image_size);
    if (image_data == NULL || temp_data == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    fseek(fp_in, HEADER_SIZE, SEEK_SET);
    fread(image_data, sizeof(unsigned char), image_size, fp_in);

    print_menu();

    char choice;
    while (1) {
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                apply_filter();
                break;
            case '2':
                save_changes();
                break;
            case '3':
                free(image_data);
                free(temp_data);
                fclose(fp_in);
                if (image_data != NULL) {
                    printf("Memory not freed!\n");
                }
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice!\n");
        }
        print_menu();
    }

    return 0;
}

void print_menu() {
    printf("\nMenu:\n");
    printf("1. Apply filter\n");
    printf("2. Save changes\n");
    printf("3. Exit\n");
}

void save_changes() {
    printf("Enter the output filename: ");
    fgets(out_filename, MAX_FILENAME_LENGTH, stdin);
    out_filename[strcspn(out_filename, "\n")] = 0;

    FILE *fp_out = fopen(out_filename, "w+b");
    if (fp_out == NULL) {
        printf("Failed to open output file!\n");
        return;
    }

    fwrite(image_data, sizeof(unsigned char), HEADER_SIZE, fp_out);
    fwrite(image_data, sizeof(unsigned char), image_size, fp_out);
    fclose(fp_out);

    printf("Changes saved successfully to %s!\n", out_filename);
}

void apply_filter() {
    memcpy(temp_data, image_data, image_size);

    //Sample filter - replace red channel values with green channel
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = i * (width * 3 + padding) + j * 3;
            temp_data[index] = temp_data[index + 1];
        }
    }

    memcpy(image_data, temp_data, image_size);

    printf("Filter applied successfully!\n");
}