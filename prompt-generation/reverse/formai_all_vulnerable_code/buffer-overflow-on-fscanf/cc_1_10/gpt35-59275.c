//FormAI DATASET v1.0 Category: Image Steganography ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void hideData(FILE *image, FILE *file, FILE *output) {
    int Byte;
    char data;
    int i = 0; 
    while((Byte = fgetc(image)) != EOF) {
        fputc(Byte, output);
        for(int j = 0; j < 8; j++) {
            if(i % 8 == 0) {
                if(fscanf(file, "%c", &data) == EOF) {
                    return;
                }
            i = 0;
            }
            if((data & (1 << i)) != 0) {
                Byte |= 1;
            }
            else {
                Byte &= ~1;
            }
            i++;
        }
        fputc(Byte, output);
    }
    return;
}

void extractData(FILE *image, FILE *output) {
    int Byte;
    int i = 0;
    char data = 0;
    while((Byte = fgetc(image)) != EOF) {
        for(int j = 0; j < 8; j++) {
            if((i % 8) == 0) {
                fputc(data, output);
                data = 0;
            }
            if((Byte & 1) != 0) {
                data |= 1 << i;
            }
            else {
                data &= ~(1 << i);
            }
            i++;
            Byte >>= 1;
        }
    }
    return;
}

int main() {
    FILE *image, *file, *output;
    int choice;
    char filename[100], imageName[100], outputname[100];
    while(1) {
        printf("\n Image Steganography \n"
                "1. Hide Data \n"
                "2. Extract Data \n"
                "3. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the name of Image file (including extension): ");
                scanf("%s", imageName);
                printf("Enter the name of Data file to hide (including extension): ");
                scanf("%s", filename);
                printf("Enter the name for the output Image file (including extension): ");
                scanf("%s", outputname);
                image = fopen(imageName, "rb");
                file = fopen(filename, "r");
                output = fopen(outputname, "wb");
                hideData(image, file, output);
                fclose(image);
                fclose(file);
                fclose(output);
                printf("Data Hided Successfully!\n");
                break;
            case 2:
                printf("Enter the name of Image file (including extension): ");
                scanf("%s", imageName);
                printf("Enter the name for the output Data file (including extension): ");
                scanf("%s", outputname);
                image = fopen(imageName, "rb");
                output = fopen(outputname, "w");
                extractData(image, output);
                fclose(image);
                fclose(output);
                printf("Data Retrieved Successfully!\n");
                break;
            case 3:
                printf("Exiting the Program\n");
                exit(1);
            default:
                printf("Invalid Input!\n");
                break;
        }
    }
    return 0;
}