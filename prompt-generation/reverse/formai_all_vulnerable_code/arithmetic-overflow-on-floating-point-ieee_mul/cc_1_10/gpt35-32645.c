//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Circuit Components
#define RESISTANCE 0
#define INDUCTANCE 1
#define CAPACITANCE 2

// Circuit Parameters
#define PI 3.14159265359
double frequency;
int circuit_type;
double circuit_parameter;

// Complex Circuit Elements
typedef struct{
  double real;
  double imaginary;
} COMPLEX;

// Complex arithmetic operations
COMPLEX add(COMPLEX a, COMPLEX b){
  COMPLEX result = {a.real + b.real, a.imaginary + b.imaginary};
  return result;
}

COMPLEX multiply(COMPLEX a, COMPLEX b){
  COMPLEX result = {(a.real*b.real - a.imaginary*b.imaginary), (a.real*b.imaginary + a.imaginary*b.real)};
  return result;
}

// Calculate impedance
COMPLEX impedance(double frequency, int circuit_type, double circuit_parameter){
  COMPLEX imped;
  if(circuit_type == RESISTANCE){
    imped.real = circuit_parameter;
    imped.imaginary = 0;
  }
  else if(circuit_type == INDUCTANCE){
    imped.real = 0;
    imped.imaginary = 2 * PI * frequency * circuit_parameter;
  }
  else if(circuit_type == CAPACITANCE){
    imped.real = 0;
    imped.imaginary = -1 / (2 * PI * frequency * circuit_parameter);
  }
  return imped;
}

// Main function
int main(){
  printf("Enter circuit frequency (Hz): ");
  scanf("%lf", &frequency);
  printf("Enter circuit component type (0 for resistance, 1 for inductance, 2 for capacitance): ");
  scanf("%d", &circuit_type);
  printf("Enter circuit parameter value: ");
  scanf("%lf", &circuit_parameter);

  COMPLEX imped = impedance(frequency, circuit_type, circuit_parameter);
  printf("Impedance = %.4f + %.4fi\n", imped.real, imped.imaginary);

  return 0;
}