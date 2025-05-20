//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_NAME_LEN 20
#define MAX_VALUE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    double factor;
} Unit;

int main() {
    int num_units;
    char input_str[MAX_VALUE_LEN];
    char *token;
    Unit units[MAX_UNITS];
    int i, j;

    printf("Welcome to the Excited Unit Converter!\n");
    printf("Please enter the number of units you want to convert from and to:\n");
    scanf("%d", &num_units);

    for(i=0; i<num_units; i++) {
        printf("Enter the name of unit %d:\n", i+1);
        scanf("%s", input_str);
        strcpy(units[i].name, input_str);

        printf("Enter the factor for %s:\n", units[i].name);
        scanf("%lf", &units[i].factor);
    }

    printf("Enter the value you want to convert:\n");
    scanf("%s", input_str);

    token = strtok(input_str, " ");
    while(token!= NULL) {
        for(i=0; i<num_units; i++) {
            if(strcmp(token, units[i].name) == 0) {
                for(j=i+1; j<num_units; j++) {
                    printf("%s = %.2lf %s\n", units[i].name, (double)atof(input_str)/units[i].factor, units[j].name);
                }
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    return 0;
}