//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char *name;
    double ( *convert )( double );
} Unit;

double meter_to_feet( double meters ) {
    return meters * 3.28084;
}

double feet_to_meter( double feet ) {
    return feet / 3.28084;
}

double kilogram_to_pound( double kilograms ) {
    return kilograms * 2.20462;
}

double pound_to_kilogram( double pounds ) {
    return pounds / 2.20462;
}

double liter_to_gallon( double liters ) {
    return liters * 0.264172;
}

double gallon_to_liter( double gallons ) {
    return gallons / 0.264172;
}

void print_units( Unit *units, int count ) {
    printf( "Available units:\n" );
    for( int i = 0; i < count; i++ ) {
        printf( "%s\n", units[i].name );
    }
}

int main() {
    Unit units[] = {
        { "Meter", meter_to_feet },
        { "Feet", feet_to_meter },
        { "Kilogram", kilogram_to_pound },
        { "Pound", pound_to_kilogram },
        { "Liter", liter_to_gallon },
        { "Gallon", gallon_to_liter },
        { NULL, NULL }
    };

    int count = 0;
    while( units[count].name!= NULL ) {
        count++;
    }

    char unit_name[20];
    double value, result;
    int choice;

    printf( "Welcome to the Unit Converter!\n" );
    printf( "Please choose a unit to convert from:\n" );
    print_units( units, count );
    scanf( "%s", unit_name );

    printf( "Enter the value to convert: " );
    scanf( "%lf", &value );

    printf( "Please choose a unit to convert to:\n" );
    print_units( units, count );
    scanf( "%s", unit_name );

    for( int i = 0; i < count; i++ ) {
        if( strcmp( unit_name, units[i].name ) == 0 ) {
            result = units[i].convert( value );
            printf( "%.2lf %s = %.2lf %s\n", value, unit_name, result, units[i].name );
            break;
        }
    }

    return 0;
}