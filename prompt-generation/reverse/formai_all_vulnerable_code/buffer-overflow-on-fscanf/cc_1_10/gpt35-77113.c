//FormAI DATASET v1.0 Category: Image Editor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define IMG_SIZE 1000

void readImageFile(unsigned char img[][IMG_SIZE], const char *filename) {
    FILE *fp = fopen(filename, "r");

    for(int i=0;i<IMG_SIZE;++i) {
        for(int j=0;j<IMG_SIZE;++j) {
            int t;
            fscanf(fp, "%d", &t);
            img[i][j] = (unsigned char)t;
        }
    }

    fclose(fp);
}

void writeImageFile(unsigned char img[][IMG_SIZE], const char *filename) {
    FILE *fp = fopen(filename, "w");

    for(int i=0;i<IMG_SIZE;++i) {
        for(int j=0;j<IMG_SIZE;++j) {
            fprintf(fp, "%d ", img[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void applyThreshold(unsigned char img[][IMG_SIZE], unsigned char threshold, const int rows_per_thread) {
    #pragma omp parallel for schedule(static) num_threads(4)
    for(int i = 0; i < IMG_SIZE; i+=rows_per_thread) {
        int start = i;
        int end = i+rows_per_thread;
        for(int j = start; j < end; j++) {
            for(int k = 0; k < IMG_SIZE; k++) {
                if(img[j][k] < threshold) {
                    img[j][k] = 0;
                } else {
                    img[j][k] = 255;
                }
            }
        }
    }
}

int main() {
    unsigned char img[IMG_SIZE][IMG_SIZE];
    const int rows_per_thread = IMG_SIZE/4;

    readImageFile(img, "sample_input.txt");

    applyThreshold(img, 128, rows_per_thread);

    writeImageFile(img, "output.txt");

    return 0;
}