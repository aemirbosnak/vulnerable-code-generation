//FormAI DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
float convert_to_cm(float, char*);
float convert_to_m(float, char*);
float convert_to_km(float, char*);

int main() {

  float length;
  char unit[5];

  // prompt user for input
  printf("Enter length: ");
  scanf("%f", &length);
  printf("Enter unit of measurement (cm, m or km): ");
  scanf("%s", unit);

  // convert input length to cm
  float cm_length = convert_to_cm(length, unit);
  
  // convert length to m and km
  float m_length = convert_to_m(cm_length, "cm");
  float km_length = convert_to_km(cm_length, "cm");

  // print converted lengths
  printf("\n%.2f %s = %.2f m\n", length, unit, m_length);
  printf("%.2f %s = %.2f km\n", length, unit, km_length);

  return 0;
}

// convert length to cm
float convert_to_cm(float length, char* unit) {
  float cm_length;

  if(strcmp(unit, "cm") == 0) {
    cm_length = length;
  }
  else if(strcmp(unit, "m") == 0) {
    cm_length = length * 100;
  }
  else if(strcmp(unit, "km") == 0) {
    cm_length = length * 100000;
  }
  else {
    printf("Invalid unit of measurement. Please enter cm, m or km.\n");
    exit(0);
  }

  return cm_length;
}

// convert length to m
float convert_to_m(float length, char* unit) {
  float m_length;

  if(strcmp(unit, "cm") == 0) {
    m_length = length / 100;
  }
  else if(strcmp(unit, "m") == 0) {
    m_length = length;
  }
  else if(strcmp(unit, "km") == 0) {
    m_length = length * 1000;
  }

  return m_length;
}

// convert length to km
float convert_to_km(float length, char* unit) {
  float km_length;

  if(strcmp(unit, "cm") == 0) {
    km_length = length / 100000;
  }
  else if(strcmp(unit, "m") == 0) {
    km_length = length / 1000;
  }
  else if(strcmp(unit, "km") == 0) {
    km_length = length;
  }

  return km_length;
}