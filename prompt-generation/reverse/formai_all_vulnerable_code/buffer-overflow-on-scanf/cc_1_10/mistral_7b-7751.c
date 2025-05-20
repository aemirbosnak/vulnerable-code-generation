//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265358979323846

typedef struct{
    float length;
    char unit;
}length_t;

void convert(length_t *length, char target_unit){
    switch(target_unit){
        case 'm':
            length->length *= 1.0;
            break;
        case 'km':
            length->length *= 0.001;
            break;
        case 'ft':
            length->length *= 0.3048;
            break;
        case 'yd':
            length->length *= 0.9144;
            break;
        case 'in':
            length->length *= 0.0254;
            break;
        case 'cm':
            length->length *= 0.01;
            break;
        case 'mm':
            length->length *= 0.001;
            break;
        case 'lb':
            length->length *= 2.20462;
            break;
        case 'kg':
            length->length *= 0.453592;
            break;
        case 'oz':
            length->length *= 0.035274;
            break;
        case 'st':
            length->length *= 14.0;
            break;
        case 'ton':
            length->length *= 907.1847;
            break;
        case 'gal':
            length->length *= 0.00378541;
            break;
        case 'ltr':
            length->length *= 0.001;
            break;
        case 'fl oz':
            length->length *= 0.0295735;
            break;
        case 'cup':
            length->length *= 0.0473176;
            break;
        case 'pt':
            length->length *= 0.000568261;
            break;
        default:
            printf("Invalid unit!\n");
            exit(1);
    }
}

int main(void){
    length_t length;
    char unit;

    printf("Enter length : ");
    scanf("%f%c", &length.length, &unit);

    if(unit != '\n'){
        length.unit = unit;
    }

    printf("Enter unit to convert to : ");
    scanf(" %c", &unit);

    convert(&length, unit);

    printf("Converted length : %.2f %c\n", length.length, length.unit);

    return 0;
}