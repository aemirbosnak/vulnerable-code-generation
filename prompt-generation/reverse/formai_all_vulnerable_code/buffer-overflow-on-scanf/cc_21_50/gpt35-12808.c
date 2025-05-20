//FormAI DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>

int main() {
  printf("Welcome to the Futuristic Unit Converter!\n");
  printf("Enter the number of the unit you would like to convert from:\n");
  printf("1. Kilometers\n");
  printf("2. Meters\n");
  printf("3. Centimeters\n");
  printf("4. Inches\n");
  printf("5. Feet\n");
  printf("6. Miles\n");

  int unitFrom, unitTo;
  float value, convertedValue;

  scanf("%d", &unitFrom);

  printf("Enter the number of the unit you would like to convert to:\n");
  printf("(Same options as before)\n");

  scanf("%d", &unitTo);

  printf("Enter the value you would like to convert:\n");

  scanf("%f", &value);

  if (unitFrom == 1) { //convert from kilometers
    if (unitTo == 1) { //to kilometers
      convertedValue = value;
    } else if (unitTo == 2) { //to meters
      convertedValue = value*1000; 
    } else if (unitTo == 3) { //to centimeters
      convertedValue = value*100000;
    } else if (unitTo == 4) { //to inches
      convertedValue = value*39370.1;
    } else if (unitTo == 5) { //to feet
      convertedValue = value*3280.84;
    } else if (unitTo == 6) { //to miles
      convertedValue = value/1.609;
    }
  } else if (unitFrom == 2) { //convert from meters
    if (unitTo == 1) { //to kilometers
      convertedValue = value/1000; 
    } else if (unitTo == 2) { //to meters
      convertedValue = value;
    } else if (unitTo == 3) { //to centimeters
      convertedValue = value*100;
    } else if (unitTo == 4) { //to inches
      convertedValue = value*39.3701;
    } else if (unitTo == 5) { //to feet
      convertedValue = value*3.28084;
    } else if (unitTo == 6) { //to miles
      convertedValue = value/1609.34;
    }
  } else if (unitFrom == 3) { //convert from centimeters
    if (unitTo == 1) { //to kilometers
      convertedValue = value/100000;
    } else if (unitTo == 2) { //to meters
      convertedValue = value/100;
    } else if (unitTo == 3) { //to centimeters
      convertedValue = value;
    } else if (unitTo == 4) { //to inches
      convertedValue = value/2.54;
    } else if (unitTo == 5) { //to feet
      convertedValue = value/30.48;
    } else if (unitTo == 6) { //to miles
      convertedValue = value/160934;
    }
  } else if (unitFrom == 4) { //convert from inches
    if (unitTo == 1) { //to kilometers
      convertedValue = value/39370.1;
    } else if (unitTo == 2) { //to meters
      convertedValue = value/39.3701;
    } else if (unitTo == 3) { //to centimeters
      convertedValue = value*2.54;
    } else if (unitTo == 4) { //to inches
      convertedValue = value;
    } else if (unitTo == 5) { //to feet
      convertedValue=value/12;
    } else if (unitTo == 6) { //to miles
      convertedValue = value/63360;
    }
  } else if (unitFrom == 5) { //convert from feet
    if (unitTo == 1) { //to kilometers
      convertedValue = value/3280.84;
    } else if (unitTo == 2) { //to meters
      convertedValue = value/3.28084;
    } else if (unitTo == 3) { //to centimeters
      convertedValue = value*30.48;
    } else if (unitTo == 4) { //to inches
      convertedValue = value*12;
    } else if (unitTo == 5) { //to feet
      convertedValue = value;
    } else if (unitTo == 6) { //to miles
      convertedValue = value/5280;
    }
  } else if (unitFrom == 6) { //convert from miles
    if (unitTo == 1) { //to kilometers
      convertedValue = value*1.609;
    } else if (unitTo == 2) { //to meters
      convertedValue = value*1609.34;
    } else if (unitTo == 3) { //to centimeters
      convertedValue = value*160934;
    } else if (unitTo == 4) { //to inches
      convertedValue = value*63360;
    } else if (unitTo == 5) { //to feet
      convertedValue = value*5280;
    } else if (unitTo == 6) { //to miles
      convertedValue = value;
    }
  }

  printf("%f\n", convertedValue);

  return 0;
}