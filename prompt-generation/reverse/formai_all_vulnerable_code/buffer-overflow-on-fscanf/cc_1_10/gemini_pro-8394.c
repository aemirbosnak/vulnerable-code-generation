//GEMINI-pro DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a struct to represent a complex number
typedef struct {
  double real;
  double imaginary;
} Complex;

// Function to read a complex number from a file
Complex readComplex(FILE *file) {
  Complex c;
  fscanf(file, "%lf %lf", &c.real, &c.imaginary);
  return c;
}

// Function to write a complex number to a file
void writeComplex(FILE *file, Complex c) {
  fprintf(file, "%lf %lf\n", c.real, c.imaginary);
}

// Function to add two complex numbers
Complex addComplex(Complex a, Complex b) {
  Complex c;
  c.real = a.real + b.real;
  c.imaginary = a.imaginary + b.imaginary;
  return c;
}

// Function to subtract two complex numbers
Complex subtractComplex(Complex a, Complex b) {
  Complex c;
  c.real = a.real - b.real;
  c.imaginary = a.imaginary - b.imaginary;
  return c;
}

// Function to multiply two complex numbers
Complex multiplyComplex(Complex a, Complex b) {
  Complex c;
  c.real = a.real * b.real - a.imaginary * b.imaginary;
  c.imaginary = a.real * b.imaginary + a.imaginary * b.real;
  return c;
}

// Function to divide two complex numbers
Complex divideComplex(Complex a, Complex b) {
  Complex c;
  double denominator = b.real * b.real + b.imaginary * b.imaginary;
  c.real = (a.real * b.real + a.imaginary * b.imaginary) / denominator;
  c.imaginary = (a.imaginary * b.real - a.real * b.imaginary) / denominator;
  return c;
}

// Main function
int main() {
  // Open the input file
  FILE *inputFile = fopen("input.txt", "r");
  if (inputFile == NULL) {
    printf("Error opening input file.\n");
    return EXIT_FAILURE;
  }

  // Open the output file
  FILE *outputFile = fopen("output.txt", "w");
  if (outputFile == NULL) {
    printf("Error opening output file.\n");
    return EXIT_FAILURE;
  }

  // Read the first complex number from the input file
  Complex a = readComplex(inputFile);

  // Read the second complex number from the input file
  Complex b = readComplex(inputFile);

  // Add the two complex numbers
  Complex c = addComplex(a, b);

  // Subtract the two complex numbers
  Complex d = subtractComplex(a, b);

  // Multiply the two complex numbers
  Complex e = multiplyComplex(a, b);

  // Divide the two complex numbers
  Complex f = divideComplex(a, b);

  // Write the results to the output file
  writeComplex(outputFile, c);
  writeComplex(outputFile, d);
  writeComplex(outputFile, e);
  writeComplex(outputFile, f);

  // Close the input and output files
  fclose(inputFile);
  fclose(outputFile);

  return EXIT_SUCCESS;
}