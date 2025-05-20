//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct unit{
    char from[10];
    char to[10];
    double factor;
};


void addUnit(struct unit units[], int *size){
    char from[10], to[10];
    double factor;

    printf("\nEnter the unit to be converted from: ");
    scanf("%s", from);

    printf("\nEnter the unit to be converted to: ");
    scanf("%s", to);

    printf("\nEnter the conversion factor: ");
    scanf("%lf", &factor);

    strcpy(units[*size].from, from);
    strcpy(units[*size].to, to);
    units[*size].factor = factor;

    (*size)++;
}

void displayUnits(struct unit units[], int size){
    int i;

    printf("\nThe available conversion units are:\n");

    for(i=0; i<size; i++){
        printf("\n%s -> %s : %.2lf\n", units[i].from, units[i].to, 1/units[i].factor);
    }
}

void convert(struct unit units[], int size, char choice){
    double value, result=0;
    int i;

    printf("\nEnter the value to be converted: ");
    scanf("%lf", &value);

    for(i=0; i<size; i++){
        if(strcmp(units[i].from, choice) == 0){
            result = value * units[i].factor;
            printf("\n%.2lf %s = %.2lf %s", value, choice, result, units[i].to);
            return;
        }
    }

    printf("\nInvalid choice! Please try again.");
}

int main(){
    struct unit units[MAX];
    int size=0;

    addUnit(units, &size);

    while(1){
        system("clear");

        printf("\n\n\t\t\tUnit Converter\n");
        printf("\n1. Add new conversion unit\n");
        printf("2. Display available conversion units\n");
        printf("3. Convert\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");

        char choice;
        scanf("%c", &choice);

        switch(choice){
            case '1':
                addUnit(units, &size);
                break;

            case '2':
                displayUnits(units, size);
                break;

            case '3':
                printf("\nEnter the unit to be converted from: ");
                char from[10];
                scanf("%s", from);

                convert(units, size, from);
                break;

            case '4':
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.");
        }
    }

    return 0;
}