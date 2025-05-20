//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the function to calculate the area of a triangle
double triangle_area(double base, double height) {
  return 0.5 * base * height;
}

// Define the function to calculate the volume of a sphere
double sphere_volume(double radius) {
  return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

// Define the function to calculate the surface area of a sphere
double sphere_surface_area(double radius) {
  return 4.0 * M_PI * pow(radius, 2);
}

// Define the function to calculate the factorial of a number
long factorial(long number) {
  if (number == 0) {
    return 1;
  } else {
    return number * factorial(number - 1);
  }
}

// Define the function to calculate the greatest common divisor (GCD) of two numbers
long gcd(long a, long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// Define the function to calculate the least common multiple (LCM) of two numbers
long lcm(long a, long b) {
  return (a * b) / gcd(a, b);
}

// Define the function to calculate the sum of the first n natural numbers
long sum_of_natural_numbers(long n) {
  return (n * (n + 1)) / 2;
}

// Define the function to calculate the sum of the first n odd natural numbers
long sum_of_odd_natural_numbers(long n) {
  return n * n;
}

// Define the function to calculate the sum of the first n even natural numbers
long sum_of_even_natural_numbers(long n) {
  return n * (n + 1);
}

// Define the function to check if a number is prime
int is_prime(long number) {
  if (number <= 1) {
    return 0;
  }
  for (long i = 2; i <= sqrt(number); i++) {
    if (number % i == 0) {
      return 0;
    }
  }
  return 1;
}

// Define the function to generate a random number between min and max
double random_number(double min, double max) {
  return min + (max - min) * ((double)rand() / RAND_MAX);
}

int main() {
  // Example usage of the functions

  // Calculate the area of a triangle
  double base = 10.0;
  double height = 5.0;
  double area = triangle_area(base, height);
  printf("The area of the triangle is: %.2f\n", area);

  // Calculate the volume of a sphere
  double radius = 5.0;
  double volume = sphere_volume(radius);
  printf("The volume of the sphere is: %.2f\n", volume);

  // Calculate the surface area of a sphere
  double surface_area = sphere_surface_area(radius);
  printf("The surface area of the sphere is: %.2f\n", surface_area);

  // Calculate the factorial of a number
  long number = 5;
  long factorial_result = factorial(number);
  printf("The factorial of %ld is: %ld\n", number, factorial_result);

  // Calculate the GCD of two numbers
  long a = 12;
  long b = 18;
  long gcd_result = gcd(a, b);
  printf("The GCD of %ld and %ld is: %ld\n", a, b, gcd_result);

  // Calculate the LCM of two numbers
  long lcm_result = lcm(a, b);
  printf("The LCM of %ld and %ld is: %ld\n", a, b, lcm_result);

  // Calculate the sum of the first n natural numbers
  long n = 10;
  long sum_of_natural_numbers_result = sum_of_natural_numbers(n);
  printf("The sum of the first %ld natural numbers is: %ld\n", n, sum_of_natural_numbers_result);

  // Calculate the sum of the first n odd natural numbers
  long sum_of_odd_natural_numbers_result = sum_of_odd_natural_numbers(n);
  printf("The sum of the first %ld odd natural numbers is: %ld\n", n, sum_of_odd_natural_numbers_result);

  // Calculate the sum of the first n even natural numbers
  long sum_of_even_natural_numbers_result = sum_of_even_natural_numbers(n);
  printf("The sum of the first %ld even natural numbers is: %ld\n", n, sum_of_even_natural_numbers_result);

  // Check if a number is prime
  long number_to_check = 13;
  int is_prime_result = is_prime(number_to_check);
  if (is_prime_result) {
    printf("The number %ld is prime.\n", number_to_check);
  } else {
    printf("The number %ld is not prime.\n", number_to_check);
  }

  // Generate a random number between min and max
  double min = 0.0;
  double max = 10.0;
  double random_number_result = random_number(min, max);
  printf("The random number between %.2f and %.2f is: %.2f\n", min, max, random_number_result);

  return 0;
}