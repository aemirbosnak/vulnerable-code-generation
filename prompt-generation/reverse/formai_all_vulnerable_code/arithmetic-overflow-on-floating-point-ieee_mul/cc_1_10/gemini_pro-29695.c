//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
  double x, y, z;
} vec3;

typedef struct {
  vec3 position;
  double radius;
} sphere;

typedef struct {
  vec3 position;
  vec3 direction;
} ray;

typedef struct {
  double t;
  vec3 point;
  vec3 normal;
  sphere *sphere;
} intersection;

double dot(vec3 a, vec3 b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3 vec3_add(vec3 a, vec3 b) {
  return (vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

vec3 vec3_sub(vec3 a, vec3 b) {
  return (vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

vec3 vec3_mul(vec3 a, double b) {
  return (vec3){a.x * b, a.y * b, a.z * b};
}

vec3 vec3_div(vec3 a, double b) {
  return (vec3){a.x / b, a.y / b, a.z / b};
}

vec3 vec3_normalize(vec3 a) {
  double magnitude = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
  return vec3_div(a, magnitude);
}

double intersect_ray_sphere(ray ray, sphere sphere) {
  vec3 oc = vec3_sub(ray.position, sphere.position);
  double a = dot(ray.direction, ray.direction);
  double b = 2.0 * dot(ray.direction, oc);
  double c = dot(oc, oc) - sphere.radius * sphere.radius;
  double discriminant = b * b - 4 * a * c;
  if (discriminant < 0) {
    return -1;
  } else {
    return (-b - sqrt(discriminant)) / (2.0 * a);
  }
}

intersection find_closest_intersection(ray ray, sphere *spheres, int num_spheres) {
  double closest_t = INFINITY;
  intersection closest_intersection = {INFINITY, {0, 0, 0}, {0, 0, 0}, NULL};
  for (int i = 0; i < num_spheres; i++) {
    double t = intersect_ray_sphere(ray, spheres[i]);
    if (t > 0 && t < closest_t) {
      closest_t = t;
      closest_intersection.t = t;
      closest_intersection.point = vec3_add(ray.position, vec3_mul(ray.direction, t));
      closest_intersection.normal = vec3_normalize(vec3_sub(closest_intersection.point, spheres[i].position));
      closest_intersection.sphere = &spheres[i];
    }
  }
  return closest_intersection;
}

void render(sphere *spheres, int num_spheres) {
  char buffer[WIDTH * HEIGHT];
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      double fov = M_PI / 3.0;
      double aspect_ratio = (double)WIDTH / HEIGHT;
      double x_norm = (2 * (x + 0.5) / WIDTH - 1) * tan(fov / 2.0) * aspect_ratio;
      double y_norm = (1 - 2 * (y + 0.5) / HEIGHT) * tan(fov / 2.0);
      ray ray = {{0, 0, 0}, {x_norm, y_norm, -1}};
      intersection intersection = find_closest_intersection(ray, spheres, num_spheres);
      buffer[y * WIDTH + x] = intersection.t != INFINITY ? '#' : ' ';
    }
  }
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%c", buffer[y * WIDTH + x]);
    }
    printf("\n");
  }
}

int main() {
  sphere spheres[] = {
    {{0, 0, 0}, 1},
    {{2, 0, 0}, 1},
    {{-2, 0, 0}, 1}
  };
  render(spheres, 3);
  return 0;
}