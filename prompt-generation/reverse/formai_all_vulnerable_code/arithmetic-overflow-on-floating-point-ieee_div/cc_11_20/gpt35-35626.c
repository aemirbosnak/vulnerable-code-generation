//FormAI DATASET v1.0 Category: Digital signal processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592654

int main() {

   int i, j, k, N, M;
   double f1, f2, fs, T, t;
   double x, y, theta, omega, Hr, Hi, A, C;
   double *xr, *xi, *Hrarray, *Hiarray;

   printf("Enter signal length (N): ");
   scanf("%d", &N);

   xr = (double*) malloc(N * sizeof(double));
   xi = (double*) malloc(N * sizeof(double));
   Hrarray = (double*) malloc(N * sizeof(double));
   Hiarray = (double*) malloc(N * sizeof(double));

   if (xr == NULL || xi == NULL || Hrarray == NULL || Hiarray == NULL) {
      printf("Memory allocation failed. Terminating program...\n");
      exit(EXIT_FAILURE);
   }

   printf("Enter first frequency (f1): ");
   scanf("%lf", &f1);
   printf("Enter second frequency (f2): ");
   scanf("%lf", &f2);
   printf("Enter sampling frequency (fs): ");
   scanf("%lf", &fs);
   M = floor(N/2);
   T = (double) N / fs;

   for (i = 0; i < N; i++) {
      t = (double) i / fs;
      xr[i] = sin(2*PI*f1*t) + 0.5*sin(2*PI*f2*t);
      xi[i] = 0;
   }

   for (k = 0; k < N; k++) {
      Hrarray[k] = 2*cos(2*PI*k/N);
      Hiarray[k] = 2*sin(2*PI*k/N);
   }

   for (k = 0; k < M; k++) {
      Hr = Hrarray[k];
      Hi = Hiarray[k];
      for (j = k+1; j < N-k; j++) {
         A = Hr*xr[j] - Hi*xi[j];
         C = Hr*xi[j] + Hi*xr[j];
         xr[j] = xr[j-k] - A;
         xi[j] = xi[j-k] - C;
         xr[j-k] += A;
         xi[j-k] += C;
      }
   }

   for (i = 0; i < N; i++) {
      theta = 2*PI*i/N;
      omega = theta/T;
      x = 0;
      y = 0;
      for (k = 0; k < N; k++) {
         x += xr[k]*cos(omega*k) + xi[k]*sin(omega*k);
         y += -xr[k]*sin(omega*k) + xi[k]*cos(omega*k);
      }
      printf("%lf %lf\n", omega/(2*PI), sqrt(x*x+y*y)/N);
   }

   free(xr);
   free(xi);
   free(Hrarray);
   free(Hiarray);

   return 0;
}