//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char str[100];
    int i, j, k, n;
    double x, y, z;
    float a, b, c;
    char c1, c2, c3;

    scanf("%s", str);
    i = 0;
    while (str[i]!= '\0') {
        if (isdigit(str[i])) {
            j = 0;
            while (isdigit(str[i+j])) {
                j++;
            }
            if (isalpha(str[i-1])) {
                c1 = str[i-1];
                c2 = str[i];
                c3 = str[i+1];
                if (c1 == 'x') {
                    x = atof(str+j);
                    printf("%lf\n", x);
                } else if (c1 == 'y') {
                    y = atof(str+j);
                    printf("%lf\n", y);
                } else if (c1 == 'z') {
                    z = atof(str+j);
                    printf("%lf\n", z);
                } else if (c1 == 'a') {
                    a = atof(str+j);
                    printf("%f\n", a);
                } else if (c1 == 'b') {
                    b = atof(str+j);
                    printf("%f\n", b);
                } else if (c1 == 'c') {
                    c = atof(str+j);
                    printf("%f\n", c);
                } else {
                    printf("Invalid variable name.\n");
                }
            } else {
                printf("Invalid variable name.\n");
            }
        }
        i++;
    }
    return 0;
}