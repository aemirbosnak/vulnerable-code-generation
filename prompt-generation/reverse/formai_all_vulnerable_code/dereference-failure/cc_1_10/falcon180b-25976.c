//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    int i, j, n, m, c, s;
    char str[1000];
    char *p;
    Point *points;
    FILE *fp;
    time_t t;
    struct tm *tm;
    char *date_str;

    // Allocate memory for points
    points = (Point*) malloc(1000 * sizeof(Point));

    // Read QR code data from file
    fp = fopen("qrcode.txt", "r");
    fscanf(fp, "%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            fscanf(fp, "%d", &c);
            points[i * m + j].x = c;
        }
    }
    fclose(fp);

    // Generate QR code image
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (points[i * m + j].x == 0) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }

    // Save image to file
    t = time(NULL);
    tm = localtime(&t);
    date_str = asctime(tm);
    strcat(str, "QR code generated on ");
    strcat(str, date_str);
    fp = fopen("qrcode.txt", "w");
    fprintf(fp, "%s", str);
    fclose(fp);

    // Free memory
    free(points);

    return 0;
}