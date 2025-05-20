//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.14159265358979323846

typedef struct planet
{
	double mass;
	double x, y, z;
	double vx, vy, vz;
} planet;

void update_velocities(planet *p, int n)
{
	int i, j;
	double dx, dy, dz, r, f;
	for (i = 0; i < n; i++)
	{
		p[i].vx = 0;
		p[i].vy = 0;
		p[i].vz = 0;
		for (j = 0; j < n; j++)
		{
			if (i == j) continue;
			dx = p[j].x - p[i].x;
			dy = p[j].y - p[i].y;
			dz = p[j].z - p[i].z;
			r = sqrt(dx * dx + dy * dy + dz * dz);
			f = (p[i].mass * p[j].mass) / (r * r);
			p[i].vx += f * dx / r;
			p[i].vy += f * dy / r;
			p[i].vz += f * dz / r;
		}
	}
}

void update_positions(planet *p, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		p[i].x += p[i].vx;
		p[i].y += p[i].vy;
		p[i].z += p[i].vz;
	}
}

int main()
{
	int i, n;
	double t, dt;
	planet *p;
	FILE *fp;

	fp = fopen("planets.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file.\n");
		return 1;
	}
	fscanf(fp, "%d", &n);
	p = malloc(n * sizeof(planet));
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%lf %lf %lf %lf %lf %lf %lf", &p[i].mass, &p[i].x, &p[i].y, &p[i].z, &p[i].vx, &p[i].vy, &p[i].vz);
	}
	fclose(fp);

	t = 0;
	dt = 0.001;
	while (t < 100)
	{
		update_velocities(p, n);
		update_positions(p, n);
		t += dt;
	}

	fp = fopen("planets_out.txt", "w");
	if (fp == NULL)
	{
		printf("Error opening file.\n");
		return 1;
	}
	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%lf %lf %lf %lf %lf %lf %lf\n", p[i].mass, p[i].x, p[i].y, p[i].z, p[i].vx, p[i].vy, p[i].vz);
	}
	fclose(fp);

	return 0;
}