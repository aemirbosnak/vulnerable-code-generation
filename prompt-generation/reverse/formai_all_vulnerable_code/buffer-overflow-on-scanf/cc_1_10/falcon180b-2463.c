//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERSION_TYPES 10
#define MAX_CONVERSION_FACTORS 5

typedef struct {
    char *name;
    double factor;
} ConversionType;

int main() {
    int numConversions;
    scanf("%d", &numConversions);

    ConversionType conversionTypes[MAX_CONVERSION_TYPES];
    for(int i = 0; i < numConversions; i++) {
        conversionTypes[i].name = malloc(100 * sizeof(char));
        conversionTypes[i].factor = 0;
        printf("Enter conversion type %d: ", i+1);
        scanf("%s", conversionTypes[i].name);
        printf("Enter conversion factor: ");
        scanf("%lf", &conversionTypes[i].factor);
    }

    int numConversionsInput;
    printf("Enter number of conversions to perform: ");
    scanf("%d", &numConversionsInput);

    double inputValue;
    char inputUnit[50];
    char outputUnit[50];

    for(int i = 0; i < numConversionsInput; i++) {
        printf("Enter input value: ");
        scanf("%lf", &inputValue);
        printf("Enter input unit: ");
        scanf("%s", inputUnit);

        int conversionTypeIndex = -1;
        for(int j = 0; j < numConversions; j++) {
            if(strcmp(conversionTypes[j].name, inputUnit) == 0) {
                conversionTypeIndex = j;
                break;
            }
        }

        if(conversionTypeIndex == -1) {
            printf("Invalid input unit.\n");
            continue;
        }

        int outputTypeIndex = -1;
        printf("Enter output unit: ");
        scanf("%s", outputUnit);
        for(int k = 0; k < numConversions; k++) {
            if(strcmp(conversionTypes[k].name, outputUnit) == 0) {
                outputTypeIndex = k;
                break;
            }
        }

        if(outputTypeIndex == -1) {
            printf("Invalid output unit.\n");
            continue;
        }

        double outputValue = inputValue * conversionTypes[conversionTypeIndex].factor / conversionTypes[outputTypeIndex].factor;
        printf("%.2lf %s = %.2lf %s\n", inputValue, inputUnit, outputValue, outputUnit);
    }

    return 0;
}